#include <stdio.h>
int contar_valor_en_array(int,int*,unsigned int,int*);
int sumar_diagonal(long*,unsigned int ,long*);
int ordenar(int*, unsigned int);
int main()
{
	int ejercicio=3;
	int ret;
	if(ejercicio==1)
	{
		int array[10] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 3};
		int valor = 3;
		int cuenta=0;
		unsigned int id=10;
		ret = contar_valor_en_array(valor, array, id, &cuenta);
		if(ret != 0)
		{
			printf("\nEl valor %d aparece %u veces.", valor, cuenta);
		}
		else
		{
			printf("\nError");
		}
	}
	else
	{
		if(ejercicio==2)
		{
			unsigned int num_filas_columnas=3;
			long matriz[3][3]={{1,2,3},{1,2,3},{1,2,3}};
			long resultado=0;
			ret=sumar_diagonal(matriz,num_filas_columnas,&resultado);
			printf("Resultado: %ld ",resultado);
		}
		else
		{
			unsigned int longitud=4;
			int array[4]={6,8,7,1};
			ret=ordenar(array,longitud);
			if(ret)printf("ordenado");
		}
	}

	return 0;
}
