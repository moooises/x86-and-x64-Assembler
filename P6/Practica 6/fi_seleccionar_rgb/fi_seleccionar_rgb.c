//-----------------------------------------------------------------------------------------------------
/// \file	fi_seleccionar_rgb.h
//

#include "fi_seleccionar_rgb.h"
#include <immintrin.h>

//-----------------------------------------------------------------------------------------------------
/// \brief          Seleccionar componentes de color de una imagen RGB.
///
/// \param[in,out]  ptr_imagen      Puntero a los datos de la imagen. Cada pixel ocupa tres bytes
///                                 con las componentes azul, verde y roja (en ese orden). El puntero
///                                 debe estar alineado a una posici�n divisible entre 32.
///
/// \param[in]      ancho           ancho de la imagen en pixels.
///
/// \param[in]      alto            alto de la imagen en pixels.
///
/// \param[in]      seleccion_rgb   m�scara para seleccionar qu� componentes de color se conservan:
///                                 Si el bit 0 de seleccion_rgb est� a 1 se conserva la componente azul.
///                                 Si est� a 0 se elimina.
///                                 Si el bit 1 de seleccion_rgb est� a 1 se conserva la componente verde.
///                                 Si est� a 1 se elimina.
///                                 Si el bit 2 de seleccion_rgb est� a 1 se conserva la componente roja.
///                                 Si est� a 2 se elimina.
///
/// \return			0 => error (ptr_imagen nulo o no alineado o ancho == 0 o alto == 0), 1 => �xito.
//

int fi_seleccionar_rgb(unsigned char *ptr_imagen,
                       unsigned int ancho,
                       unsigned int alto,
                       unsigned char seleccion_rgb)
{
  if(ptr_imagen!=NULL && ((unsigned long)ptr_imagen&0x1F)==0 && ancho>0 && alto>0){

    unsigned int nPixeles = ancho*alto;
    //Mascaras
    unsigned char maskA1V3R2[32] __attribute__ ((aligned(32))) = {0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0 , 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0};
    unsigned char maskA2V1R3[32] __attribute__ ((aligned(32))) = {0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0 ,0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF};
    unsigned char maskA3V2R1[32] __attribute__ ((aligned(32))) = {0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0 ,0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF,0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0, 0xFF, 0, 0};


    //mascaras finales para cuando ya se tienen los colores que se mantienen
    __m256i maskFinal1, maskFinal2, maskFinal3,mask1,mask2,mask3;
    mask1 = _mm256_load_si256((__m256i*)maskA1V3R2);
    mask2 = _mm256_load_si256((__m256i*)maskA2V1R3);
    mask3 = _mm256_load_si256((__m256i*)maskA3V2R1);
  maskFinal1 = maskFinal2 = maskFinal3 =  _mm256_setzero_si256();

  //Cargar en la mascara final los bytes para mantener el color azul
    if((seleccion_rgb & 0x01) != 0){
      maskFinal1 = _mm256_or_si256(maskFinal1, mask1);
      maskFinal2 = _mm256_or_si256(maskFinal2, mask2);
      maskFinal3 = _mm256_or_si256(maskFinal3, mask3);
    }

    //color verde
    if((seleccion_rgb & 0x02) != 0){
      maskFinal1 = _mm256_or_si256(maskFinal1, mask2);
      maskFinal2 = _mm256_or_si256(maskFinal2, mask3);
      maskFinal3 = _mm256_or_si256(maskFinal3, mask1);
    }

    //color rojo
    if((seleccion_rgb & 0x04) != 0){
      maskFinal1 = _mm256_or_si256(maskFinal1, mask3);
      maskFinal2 = _mm256_or_si256(maskFinal2, mask1);
      maskFinal3 = _mm256_or_si256(maskFinal3, mask2);
    }

    unsigned int itAvx = nPixeles/32; 		//itAvx = numero de iteraciones del bucle que modificara de 32 en 32 pixeles
    unsigned int restos = nPixeles%32;	//restos = numero de iteraciones para el bloque de pixeles de menos de 32

    if(itAvx > 0){
    __m256i pixeles1, pixeles2, pixeles3;
    __m256i* ptr1 = (__m256i*) ptr_imagen;
    __m256i* ptr2 = ((__m256i*) ptr_imagen) + 1;
    __m256i* ptr3 = ((__m256i*) ptr_imagen) + 2;

    for(int i=0; i<itAvx; i++){
      pixeles1 = _mm256_load_si256(ptr1);
      pixeles2 = _mm256_load_si256(ptr2);
      pixeles3 = _mm256_load_si256(ptr3);

      pixeles1 = _mm256_and_si256(pixeles1, maskFinal1);
      pixeles2 = _mm256_and_si256(pixeles2, maskFinal2);
      pixeles3 = _mm256_and_si256(pixeles3, maskFinal3);
      _mm256_store_si256(ptr1, pixeles1);
      _mm256_store_si256(ptr2, pixeles2);
      _mm256_store_si256(ptr3, pixeles3);
      ptr1 += 3;
      ptr2 += 3;
      ptr3 += 3;
    }
    }

    if(restos > 0){
      ptr_imagen += (itAvx*32*3);
      for(int i=0; i<restos; i++){
        //Si el bit de azul esta activado
        if((seleccion_rgb & 0x01) == 0)
          *ptr_imagen = 0;

        //Si el bit de verde esta activo
        if((seleccion_rgb & 0x02) == 0)
          *(ptr_imagen + 1) = 0;

        //Si el bit de rojo esta activo
        if((seleccion_rgb & 0x04) == 0)
          *(ptr_imagen + 2) = 0;

        //Incrementar el puntero al siguiente pixel(3 siguiente bytes)
        ptr_imagen += 3;
      }
    }
    return 1;
  }


  return 0;
}
