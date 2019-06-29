#include <stdio.h>
char* uint_a_cadena_binario(unsigned int , char * );
int convertir_celcius_fahrenheit(int ,int ,int *);
void * copiar_bloque_memoria(void * destino,void * origen,unsigned int longitud);
int main()
{
int ejercicio=3;

if(ejercicio==1)
{
	char buffer[33];
	printf("%s",uint_a_cadena_binario(124,buffer));
}
else
{
	if(ejercicio==2)
	{
		int dato=0;
		printf("%d",convertir_celcius_fahrenheit(-42,0,&dato));

	}
	else
	{
		if(ejercicio==3)
		{

			unsigned int longitud=27;
			int destino;
			int origen=5;
			copiar_bloque_memoria(&destino,&origen,longitud);
			printf("%d",destino);

		}
	}
}


return 0;
}
