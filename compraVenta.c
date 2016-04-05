#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct producto
{
	int valor;
	unsigned char nombreProducto[30];
	unsigned char precioProdu[30];
	char hayProdu[30];
	float precio;
	unsigned int hay;
	struct producto *sig;

}Producto;

void imprimirMenuPrincipal();
void desplegarListaProductos(FILE *registro,int *departamento);
int contarTipoProducto(FILE *registro);
Producto* crearListaProductos(FILE *registro, int numeroProductos);
Producto* asignarInformacionProductos(Producto* lista, FILE* registro, int numeroProductos);
void comprar(Producto* lista,int index,FILE* registro,int *departamento, int numeroProductos);
void lanzadorError(FILE* apuntador);
void fflushin();

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
					printf("Sentimos las molestias este departamento no esta displonible\n");
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
					printf("Sentimos las molestias este departamento no esta displonible\n");
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
					printf("Sentimos las molestias este departamento no esta displonible\n");
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
					printf("Sentimos las molestias este departamento no esta displonible\n");
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
					printf("Sentimos las molestias este departamento no esta displonible\n");
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
	fflushin();
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
		if(numeroProductos > 0)
		{
			Producto *lista = crearListaProductos(registro,numeroProductos);
			lista = asignarInformacionProductos(lista,registro,numeroProductos);
			for(int i = 0; i < numeroProductos; i++)
			{
				printf("%d- %s Precio: $%s\n",i+1,lista[i].nombreProducto,lista[i].precioProdu);
			}
			printf("Opciones:\n");
			printf("1.- Desea comprar algo?\n");
			printf("2.- Salir del departamento\n");
			fflush(stdout);
			scanf("%d",&opciones);
			switch(opciones)
			{
				case 1:
					printf("Seleccione el producto que desea comprar\n");
					scanf("%d",&producto);
					producto --;
					//
					printf("numeroProductos: %d\n", numeroProductos);
					//
					//Aquí nos aseguramos de que la opcion esogida esté dentro del rango
					//Para evitar un desbordamiento.
					if(producto < numeroProductos && producto >= 0)
					{
						comprar(lista,producto,registro,departamento,numeroProductos);
					}else
					{
						printf("Por favor escoja una opcion correcta\n");
					}
				break;
				case 2:

				break;
				default:
				printf("Por favor seleccione una opcion valida\n");
				break;
			}
			rewind(registro);
			//fflushin();
		}else
		{
			printf("Lo sentimos ya no hay productos displonibles en este departamento\n");
			opciones = 2;
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

void comprar(Producto* lista, int index, FILE *registro, int* departamento, int numeroProductos)
{
	FILE *registroDepartamental;
	FILE *registroGeneral;
	registroGeneral = fopen("operacionesGeneral.txt","a");
	int departamentoSeleccionado = * departamento;
	printf("Realizando la operacion...\n");
	//Para obtener la fecha
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
	char fecha[30];
	strftime(fecha,30,"%d-%m-%y %H:%M:%S",tlocal);

	switch(departamentoSeleccionado)
	{
		case 1:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesElectronica.txt","a");
			fprintf(registroGeneral, "%s Departamento -> Electronica\t%s --> $%s\n",fecha,lista[index].nombreProducto,lista[index].precioProdu);
		break;
		case 2:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesPapeleria.txt","a");
			fprintf(registroGeneral, "%s Departamento -> Papelería\t%s --> $%s\n",fecha,lista[index].nombreProducto,lista[index].precioProdu);
		break;
		case 3:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesRopa.txt","a");
			fprintf(registroGeneral, "%s Departamento -> Ropa\t%s --> $%s\n",fecha,lista[index].nombreProducto,lista[index].precioProdu);
		break;
		case 4:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesMuebles.txt","a");
			fprintf(registroGeneral, "%s Departamento -> Muebles\t%s --> $%s\n",fecha,lista[index].nombreProducto,lista[index].precioProdu);
		break;
		case 5:
			printf("Registrando la compra...\n");
			registroDepartamental = fopen("operacionesDeportes.txt","a");
			fprintf(registroGeneral, "%s Departamento -> Deportes\t%s --> $%s\n",fecha,lista[index].nombreProducto,lista[index].precioProdu);
		break;
		default:
			printf("Easter Egg\n");
		break;
	}
	printf("Registrando la compra...\n");
	fprintf(registroDepartamental, "%s %s --> $%s\n",fecha,lista[index].nombreProducto,lista[index].precioProdu);
	printf("listo!\n");

	//En esta parte se actualizan las existencias


	int existencias = (int)strtol(lista[index].hayProdu,NULL,10);
	char * existenciaRegistrada = lista[index].hayProdu;
	int ceroExistencias = 0;


	existencias --;

	if(existencias == 0)
	{
		ceroExistencias = 1;
	}
	snprintf(lista[index].hayProdu,10,"%d",existencias);

	fclose(registro);
	//cerramos el archivo para reabrirlo en forma de escritura y sobreescribir el archivo

	switch(departamentoSeleccionado)
	{
		case 1:
			registro = fopen("electronica.txt","w+");
		break;
		case 2:
			registro = fopen("papeleria.txt","w+");
		break;
		case 3:
			registro = fopen("ropa.txt","w+");
		break;
		case 4:
			registro = fopen("muebles.txt","w+");
		break;
		case 5:
			registro = fopen("deportes.txt","w+");
		break;
		default:
			printf("Otro Easter Egg\n");
		break;
	}
	if(registro == NULL)
	{
		printf("Sentimos las molestias, el sistema esta experimentando fallos\n");
		exit(0);
	}


	if(ceroExistencias == 1)
	{
		for(int i = 0; i<numeroProductos; i++)
		{
			if(i == index)
			{
				//Se salta esta línea
			}
			else
			{
				fprintf(registro, "%s\t%s\t%s\n",lista[i].nombreProducto,lista[i].precioProdu,lista[i].hayProdu);
			}
		}

	}else
	{
		for(int i = 0; i<numeroProductos; i++)
		{
			fprintf(registro, "%s\t%s\t%s\n",lista[i].nombreProducto,lista[i].precioProdu,lista[i].hayProdu);
		}
	}

	fclose(registro);


		switch(departamentoSeleccionado)
	{
		case 1:
			registro = fopen("electronica.txt","r");
		break;
		case 2:
			registro = fopen("papeleria.txt","r");
		break;
		case 3:
			registro = fopen("ropa.txt","r");
		break;
		case 4:
			registro = fopen("muebles.txt","r");
		break;
		case 5:
			registro = fopen("deportes.txt","r");
		break;
		default:
			printf("Otro Easter Egg\n");
		break;
	}
	fclose(registroDepartamental);
	fclose(registroDepartamental);
}
void fflushin()
{
int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

