#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct producto
{
	int valor;
	unsigned char nombreProducto[30];
	unsigned char precioProdu[30];
	unsigned char hayProdu[30];
	float precio;
	unsigned int hay;
	struct producto *sig;

}Producto;

void imprimirMenuPrincipal();
void desplegarListaProductos(FILE *registro,int *departamento);
int contarTipoProducto(FILE *registro);
Producto* crearListaProductos(FILE *registro, int numeroProductos);
Producto* asignarInformacionProductos(Producto* lista, FILE* registro, int numeroProductos);
void comprar(Producto productoSeleccionado,int index,FILE* registro,int *departamento);
void lanzadorError(FILE* apuntador);

int main(int argc, char const *argv[])
{
	FILE *registro; 
	//Variable que almacena la opcion introducida por el teclado
	int Opcion;
	int departamento;

	//Incicio de ciclo interminable hasta que el usuario escoja la opcion 6.
	do
	{
		imprimirMenuPrincipal();
		//Lectura de Opcion
		scanf("%d",&Opcion);
		//Seleccion de departamento 
		switch(Opcion)
		{
			//Este switch es básicamente para que el flujo del programa siga mientras 
			//se escoja una opción diferente a la 6.
			case 1:
				registro = fopen("electronica.txt","r");
				departamento = 1;
				if( registro == NULL)
				{
					printf("Lo sentimos el sistema no está disponible\n Contacte al administrador\n");
					continue;
				}else{
					desplegarListaProductos(registro,&departamento);
				}
			break;

			case 2:
				registro = fopen("papeleria.txt","r");
				departamento = 2;
				if( registro == NULL)
				{
					printf("Lo sentimos el sistema no está disponible\n Contacte al administrador\n");
					continue;
				}else{
					desplegarListaProductos(registro,&departamento);
				}

			break; 

			case 3:
				registro = fopen("ropa.txt","r");
				departamento = 3;
				if( registro == NULL)
				{
					printf("Lo sentimos el sistema no está disponible\n Contacte al administrador\n");
					continue;
				}else{
					desplegarListaProductos(registro,&departamento);
				}

			break;

			case 4:
				registro = fopen("muebles.txt","r");
				departamento = 4;
				if( registro == NULL)
				{
					printf("Lo sentimos el sistema no está disponible\n Contacte al administrador\n");
					continue;
				}else{
					desplegarListaProductos(registro,&departamento);
				}

			break; 

			case 5:
				registro = fopen("deportes.txt","r");
				departamento = 5; 
				if( registro == NULL)
				{
					printf("Lo sentimos el sistema no está disponible\n Contacte al administrador\n");
					continue;
				}else{
					desplegarListaProductos(registro,&departamento);
				}

			break; 

			case 6:

			printf("Gracias por compra con nostros!!\nVuelva Pronto!!\n\n");

			break;

			default:

			printf("Por favor escoja una opción correcta\n");
			
			break;
		}
	fclose(registro);
	}while(Opcion != 6);
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
	printf("1. Departamento de electronica\n2. Departamento de Papelería\n3. Departamento de Ropa\n4. Departamento Muebles\n");
	printf("5. Departamento de Deportes\n6. Salir del Sistema\n\n");
	printf("Opción: \n");
}

////////////////////////////////////
//Function: desplegarListaProductos
//in: Apuntador de tipo FILE que apunta al archivo registros, apuntador de tipo entero
//		que contiene el departamento seleccionado.
//out: void
/*
Description: 
	
	En esta funcion se realizan las siguientes operaciones:
		- contar tipo de productos
		- crear arreglo dinamico de productos
		- asignación de informacion de los productos al arreglo
		- Se despliega la lista de productos
		- Se realiza la operacion de compra
		- Se actualiza el archivo registro de productos en caso 
			de que la existencia de un producto sea igual a cero.
*/

void desplegarListaProductos(FILE *registro,int * departamento)
{
	int opciones;
	int producto;
	do{
		//Primero contamos el números de productos, por tipo de producto, no por existencias.
		int numeroProductos = contarTipoProducto(registro);
		Producto *lista = crearListaProductos(registro,numeroProductos);
		lista = asignarInformacionProductos(lista,registro,numeroProductos);
		for(int i = 0; i < numeroProductos; i++)
		{
			printf("%d- %s Precio: $%s\n",i+1,lista[i].nombreProducto,lista[i].precioProdu);
		}
		printf("Opciones:\n");
		printf("1.- Desea comprar algo?\n");
		printf("2.- Salir del departamento\n");
		scanf("%d",&opciones);
		switch(opciones)
		{
			case 1:
				printf("Seleccione el producto que desea comprar\n");
				scanf("%d",&producto);
				producto --;
				//
				printf("%d\n",producto);
				printf("%s\t%s\n",lista[producto].nombreProducto,lista[producto].precioProdu);
				//
				comprar(lista[producto],producto,registro,departamento);
			break;
			case 2:

			break;
			default:
			printf("Por favor seleccione una opcion valida\n");
			break;
		}
	}while(opciones != 2);

}
////////////////////////////////////
//Function: contarTipoProducto
//in: Apuntador de tipo FILE que apunta al archivo de registros
//out: entero
/*
Description: 
	La funcion se encarga de contar el número de líneas que
	hay en el archivo, lo que equivale el número de productos
	que hay registrados.
*/

int contarTipoProducto(FILE *registro)
{
	int contador = 0;
	char caracter;

	while(feof(registro) == 0)
	{
		caracter = fgetc(registro);
		if(caracter == '\n')
		{
			contador ++; 
		}
	}
	rewind(registro);
	return contador;
}

////////////////////////////////////
//Function: crearListaProdcutos
//in: Apuntador de tipo FILE que apunta al archivo de registros
//out: Apuntador de tipo Producto
/*
Description: 
	
	La función se encarga de crear una arreglo en memoria dinámica
	con esapacios equivalentes a la estructura de dato Producto. 
*/

Producto *crearListaProductos(FILE *registr,int numeroProductos)
{
	Producto *lista = NULL;
	lista = (Producto *) calloc(numeroProductos, sizeof(Producto));
	return lista;
}

////////////////////////////////////
//Function: asignarInformacionProductos
//in: apuntador de tipo producto, apuntador de tipo FILE que apunta al archivo registro, entero numero productos
//out: apuntador de tipo productos
/*
Description: 
	
	En esta función se asigna la informacion proveniente del archivo registro al arreglo de productos	

*/

Producto *asignarInformacionProductos(Producto* lista, FILE *registro, int numeroProductos)
{
	for(int i = 0; i < numeroProductos; i++)
	{
		fscanf(registro,"%s\t%s\t%s",lista[i].nombreProducto,lista[i].precioProdu,lista[i].hayProdu);
	}
	return lista;
}
////////////////////////////////////
//Function: comprar
//in: apuntador de tipo producto, entero index, apuntador de tipo archivo que apunta al archivo registro
//		apuntador de tipo entero departamento.
//out: void
/*
Description: 
	
	Esta función se encarga de realizar la "compra" de un producto,
	que conciste en agregar la operacion en el registro de operaciones 
	departamental y general, aparte de actualizar las existencias.
*/

void comprar(Producto productoSeleccionado, int index, FILE *registro, int* departamento)
{
	FILE *registroDepartamental;
	FILE *registroGeneral;
	registroGeneral = fopen("operacionesGeneral.txt","a");
	int departamentoSeleccionado = * departamento;
	printf("Realizando la operacion...\n");
	switch(departamentoSeleccionado)
	{
		case 1:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesElectronica.txt","a");
			fprintf(registroGeneral, "Fecha: Hora: Departamento -> Electronica\t%s --> $%s\n",productoSeleccionado.nombreProducto,productoSeleccionado.precioProdu);
		break;
		case 2:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesPapeleria.txt","a");
			fprintf(registroGeneral, "Fecha: Hora: Departamento -> Papelería\t%s --> $%s\n",productoSeleccionado.nombreProducto,productoSeleccionado.precioProdu);
		break;
		case 3:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesRopa.txt","a");
			fprintf(registroGeneral, "Fecha: Hora: Departamento -> Ropa\t%s --> $%s\n",productoSeleccionado.nombreProducto,productoSeleccionado.precioProdu);
		break;
		case 4:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesMuebles.txt","a");
			fprintf(registroGeneral, "Fecha: Hora: Departamento -> Muebles\t%s --> $%s\n",productoSeleccionado.nombreProducto,productoSeleccionado.precioProdu);
		break;
		case 5:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesDeportes.txt","a");
			fprintf(registroGeneral, "Fecha: Hora: Departamento -> Deportes\t%s --> $%s\n",productoSeleccionado.nombreProducto,productoSeleccionado.precioProdu);
		break;
		default:
			printf("Easter Egg\n");
		break;
	}
	printf("Registrando la compra...\n");
	fprintf(registroDepartamental, "Fecha: Hora: %s --> $%s\n",productoSeleccionado.nombreProducto,productoSeleccionado.precioProdu);
	printf("listo!\n");
	fclose(registroDepartamental);
	fclose(registroDepartamental);
}


