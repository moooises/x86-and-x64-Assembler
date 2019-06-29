#include "qdbmp.h"
#include <stdio.h>
#include <time.h>
/**
int sse_imagen_a_blanco_y_negro(unsigned char *ptr_imagen,
                                int ancho,
                                int alto,
                                unsigned char umbral); */

int sse_sumar_filas(const float *matriz, float *suma);

int sse_producto_escalar(const float *vector_1,const float *vector_2,unsigned int dimension,float *resultado);

int main(int argc, char* argv[])
{
	/**
    BMP*    bmp;
    unsigned int ancho, alto;*/

    /* Leer la imagen original.
     */
/**
    bmp = BMP_ReadFile("imagen_grises.bmp");
    BMP_CHECK_ERROR(stdout, -1);*/

    /* Obtener el ancho y el alto.
     */
/**
    ancho = BMP_GetWidth(bmp);
    alto = BMP_GetHeight(bmp);
*/
    /* Convertir a blanco y negro.
     */

  //  sse_imagen_a_blanco_y_negro(bmp->Data, ancho, alto, 200);

    /* Escribir en disco la imagen resultante.
     */
/**
    BMP_WriteFile(bmp, "imagen_blanco_y_negro.bmp");
    BMP_CHECK_ERROR(stdout, -2);

    BMP_Free(bmp);
*/

int ejercicio=3;

if(ejercicio==2)
{
	float suma[4];
	const float matriz[4][4]__attribute__((aligned(32)))={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int r=sse_sumar_filas(matriz,suma);
	if(r)
	{
		for(int i=0;i<4;++i)
		{
			printf("%f ",suma[i]);
		}
	}
}
else
{
	const float vector_1[6]__attribute__((aligned(32)))={1,2,3,4,5,6};
	const float vector_2[6]__attribute__((aligned(32)))={1,2,3,4,5,6};
	unsigned int dimension=6;
	float resultado;

	int r;
	r=sse_producto_escalar(&vector_1,&vector_2,dimension,&resultado);
	if(r) printf(" El resultado es %f",resultado);

}


	return 0;
}
