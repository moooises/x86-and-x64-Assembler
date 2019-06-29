/*==============================================================================
* Fichero: main.c
*------------------------------------------------------------------------------
* Fichero en C para el programa de ejemplo.
* =============================================================================
*/

#include <stdio.h>
//int mayor(int x, int y);
//int eje1(int x,int y);//eje1
//int det(int a11, int a12, int a21, int a22);//eje2
unsigned int eje3(unsigned int a,unsigned int b);
int main(int argc, char *argv[])
{
	//int a, b, c;
	//char t;
	/* Desactivar el buffer de stdout para facilitar la depuración a través de
	 * la consola de Eclipse.
	 */
	setvbuf(stdout, NULL, _IONBF, 0);

	/** Eje1
	printf("\nIntroduzca un número entero: ");
	scanf("%d", &a);

	printf("\nIntroduzca otro número entero: ");
	scanf("%d", &b);

	//c = mayor(a, b);
	c=eje1(a, b);

	printf("\nEl mayor de los números es el %d", c);

	printf("\nPulse ’s’ y ENTER para salir.");

	do
	{
		scanf("%c", &t);
	}
	while(t != 's' && t != 'S');

	*/
	int c;

	/**eje2
	 c=det(2,3,4,5);
	printf("\nEl determinante es %d", c);
	*/

	c=eje3(4278190080,16777215);
	printf("\nEl determinante es %u", c);

	return 0;
}
