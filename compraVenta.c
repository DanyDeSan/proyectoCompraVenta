#include<stdio.h>
#include<stdlib.h>

void imprimirMenuPrincipal();
void desplegarListaProductos(FILE *Prodcutos);

int main(int argc, char const *argv[])
{
	//Apuntadores para abrir los archivos.
	FILE *Prodcutos;
	FILE *Cuentas;
	//Variable que almacena la opcion introducida por el teclado
	int Opcion;


	//Incicio de ciclo interminable hasta que el usuario escoja la opcion 6.
	do
	{
		imprimirMenuPrincipal();
		//Lectura de Opcion
		scanf("%d",&Opcion);
		//Seleccion de departamento 
		switch(Opcion)
		{
			//En cada caso, excepto el default,se va a abrir primero el archivo,
			//se comprobará de que el archivo existe, de lo contrario se lanzará
			//mensaje de error. Luego se desplegará la lista de prodcutos disponibles,
			//con su respectivo precio, para ello los precios estarán almacenados en un
			//arreglo, los productos cuyas existencias sean cero no aparecerán en la lista.
			case 1:

			break;

			case 2:

			break; 

			case 3:

			break;

			case 4:

			break; 

			case 5:

			break; 

			case 6:

			break;

			default:

			break;
		}
	}
	return 0;
}


////////////////////////////////////
//Function: imprimriMenuPrincipal
//in: void 
//out: void 
/*
Description: 
	Unicamente se encarga de imprimir el menu de principal del sistema
*/

void imprimirMenuPrincipal()
{
	printf("Departamentos:\n");
	printf("1. Departamento de electronica\n2. Departamento de Comida\n3. Departamento de Ropa\n4. Departamento Muebles\n");
	printf("5. Departamento de Deportes\n6. Salir del Sistema\n\n");
	printf("Opción: ");
}


////////////////////////////////////
//Function: desplegarListaProductos
//in: apuntador de tipo FILE
//out: void 
/*
Description:
	La función imprime en forma de lista los productos guardados en un archivo,
	con sus respectivos precios, los productos con existencias igual a 0
	no se desplegarán en la lista. 

*/
void desplegarListaProductos(FILE *Prodcutos)
{

}
