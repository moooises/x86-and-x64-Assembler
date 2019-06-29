#include <iostream>
using namespace std;

extern "C"
{
int calcular_histograma(const unsigned char* ptr_datos,unsigned int num_datos,unsigned int *ptr_histograma);
int empaquetar(const struct estructura *origen,struct estructura_empaquetada *destino);
int desempaquetar(const struct estructura_empaquetada *origen,struct estructura *destino);
int es_palindromo(const char *cadena);
}

struct estructura
{
	short a;
	char b[3];
	int c;
	long d;
};

struct estructura_empaquetada
{
	short a;
	char b[3];
	int c;
	long d;
}__attribute__((packed));

int main()
{
	int ejercicio=3;

	if(ejercicio==1)
	{
	unsigned char array[15] = {3, 5, 4, 4, 4, 4, 2, 2, 5, 5, 5, 5, 3, 1, 3};
	unsigned int histograma[256];
	cout<<calcular_histograma(array, 15, histograma)<<endl;;
	for(int i=0;i<256;++i)cout<<histograma[i]<<" ";
	cout<<endl;
	}
	else
	{
		if(ejercicio==3)
		{

			bool emp=true;
			if(emp)
			{
				estructura origen;
				estructura_empaquetada destino;
				origen.a=2;
				origen.b[0]='a';
				origen.b[1]='b';
				origen.b[2]='c';
				origen.c=32;
				origen.d=2024;

				if(empaquetar(&origen,&destino))cout<<"Bien hecho"<<endl;
				else cout<<"Mal hecho"<<endl;
			}
			else
			{
				estructura destino;
				estructura_empaquetada origen;
				origen.a=2;
				origen.b[0]='a';
				origen.b[1]='b';
				origen.b[2]='c';
				origen.c=32;
				origen.d=2024;

				if(desempaquetar(&origen,&destino))cout<<"Bien hecho"<<endl;
				else cout<<"Mal hecho"<<endl;
			}

		}
		else
		{
		const char * cadena="1234554321";
		int r=es_palindromo(cadena);

		if(r==1)cout<<"Es palindromo"<<endl;
		else
		{
			if(r==0)cout<<"No es palindromo"<<endl;
			else cout<<"Puntero nulo"<<endl;
		}
		}
	}
}



