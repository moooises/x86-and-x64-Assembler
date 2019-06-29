#include <stdio.h>
#include<immintrin.h>

int fi_sumar_matrices_4x4_double(const double *ptr_matriz_1,const double *ptr_matriz_2,double *ptr_matriz_suma);
int fi_media_floats(float *ptr_datos,unsigned int longitud_array,float *ptr_resultado);

int fi_sumar_matrices_4x4_double(const double *ptr_matriz_1,const double *ptr_matriz_2,double *ptr_matriz_suma)
{
	__m256d register1=_mm256_load_pd(ptr_matriz_1);
	__m256d register2=_mm256_load_pd(ptr_matriz_2);
	if(!_mm256_testc_pd(register1,register2))return 0;
	__m256d suma=_mm256_add_pd(register1,register2);
	_mm256_store_pd(ptr_matriz_suma,suma);

	//EL DIRECCIONAMIENTO VA DE 1 EN 1, SE MULTIPLICA POR 4 POR QUE HAY 4 ELEMENTOS
	//printf("%f",suma);
	for(int i=1;i<4;++i)
	{
		register1=_mm256_load_pd(ptr_matriz_1+4*i);
		register2=_mm256_load_pd(ptr_matriz_2+4*i);
		suma=_mm256_add_pd(register1,register2);
		_mm256_store_pd(ptr_matriz_suma+4*i,suma);
	}

return 1;
}

int fi_media_floats(float *ptr_datos,unsigned int longitud_array,float *ptr_resultado)
{

	int i=0;

	__m256 register1;
	__m256 register2;
	__m256 registerr=_mm256_set1_ps(0);

	while((longitud_array-i>=8))
	{
		register1=_mm256_load_ps(ptr_datos+i);
		register1=_mm256_hadd_ps(register1,register1);
		register1=_mm256_hadd_ps(register1,register1);
		register2=_mm256_permute2f128_ps(register1,register1,1);
		register1=_mm256_add_ps(register1,register2);
		registerr=_mm256_add_ps(register1,registerr);
		i=i+8;
	}
		__m128 r=_mm256_castps256_ps128(registerr);
		_mm_store_ss(ptr_resultado,r);


	while(i!=longitud_array)
	{
		*ptr_resultado=*ptr_resultado+(*ptr_datos+i);
		++i;
	}
	*ptr_resultado=*ptr_resultado/longitud_array;


	return 1;
}



int main()
{
	int ejercicio=2;
	if(ejercicio==1)
	{
		const double matriz1[4][4]__attribute__((aligned(32)))={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
		const double matriz2[4][4]__attribute__((aligned(32)))={{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}};

		double matrizr[4][4];

		int a;
		a=fi_sumar_matrices_4x4_double(matriz1,matriz2,matrizr);
		if(a)
		{
			for(int i=0;i<4;++i)
			{
				for(int j=0;j<4;++j)
				{
					printf(" %f ",matrizr[i][j]);
				}
				printf("\n");
			}
		}
	}
	else
	{
		if(ejercicio==2)
		{
			float datos[20]__attribute__((aligned(32)))={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
			float media=0;
			int b=fi_media_floats(datos,20,&media);
			if(b)
			{
				printf("%f",media);
			}
		}
	}
	return 0;
}
