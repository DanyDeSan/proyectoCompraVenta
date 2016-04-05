#include <locale.h> //setlocale
#include <stdio.h> //printf, scanf
#include <stdlib.h> //calloc, exit
#include <string.h> //strlen

//Estructura para los contactos:
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

//Prototipos de funciones a utilizar:
Producto* crearProducto(int num);
Producto* ingresarProducto(Producto *inicio,int num);
void leerProducto(Producto *inicio, int num);
void imprimirProductos(Producto *inicio,int num);
Producto* liberaMemoria(Producto *inicio);
Producto* eliminarProducto(Producto *inicio, int indice);
int obtenerProducto(Producto *inicio, int indice);
void grabar_archivo(FILE *archivo, Producto *inicio, int num,int opcion);
void cargar_archivo(FILE *archivo, Producto *inicio,int opcion);
int contar_renglones(FILE *archivo);
//Producto* Push(Producto *inicio, int v);
//int Pop(Producto *inicio);

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL,"Spanish_Mexico");

	FILE *archivo=NULL;
	Producto *lista=NULL;
	int num=0,i=0, opcion=0,indice=0,obtener;


	do{
		
		printf("\nOpciones de la Tienda: \n\n");
		printf("1. Departamento de electronica: \n");
		printf("2. Departamento papeleria: \n");
		printf("3. Departamento ropa: \n");
		printf("4. Departamento muebles: \n");
		printf("5. Departamento deportes: \n");
		printf("6. Salir del programa: \n\n");

		printf("Aque departamento decia ir: ");
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1:
            		printf("\nIngrese el numero de productos: ");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);

					do{

					printf("\n\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea importar productos de un archivo de texto: \n");
					printf("5. Desea exportar productos a un archivo de  texto: \n");
					printf("6. Salir del programa: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								imprimirProductos(lista,num);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								imprimirProductos(lista,num);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								cargar_archivo(archivo,lista,1);
								break;

					    case 5:
					     		grabar_archivo(archivo,lista,num,1);
					     		break;

					    case 6:
					     		printf("\n Fin del programa... \n");
					            break;

						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=6);				
										
			        break;
      		case 2:
      				printf("\nIngrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					

					do{

					printf("\n\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea importar productos de un archivo de texto: \n");
					printf("5. Desea exportar productos a un archivo de  texto: \n");
					printf("6. Salir del programa: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								imprimirProductos(lista,num);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								cargar_archivo(archivo,lista,2);
								break;

					    case 5:
					     		grabar_archivo(archivo,lista,num,2);
					     		break;

					    case 6:
					     		printf("\n Fin del programa... \n");
					            break;

						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=6);				
										
			        break;					
      		case 3:
            		printf("\n\nIngrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea importar productos de un archivo de texto: \n");
					printf("5. Desea exportar productos a un archivo de  texto: \n");
					printf("6. Salir del programa: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								imprimirProductos(lista,num);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								cargar_archivo(archivo,lista,3);
								break;

					    case 5:
					     		grabar_archivo(archivo,lista,num,3);
					     		break;

					    case 6:
					     		printf("\n Fin del programa... \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=6);				
										
			        break;
            case 4:
            		printf("\n\nIngrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea importar productos de un archivo de texto: \n");
					printf("5. Desea exportar productos a un archivo de  texto: \n");
					printf("6. Salir del programa: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								imprimirProductos(lista,num);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								cargar_archivo(archivo,lista,4);
								break;

					    case 5:
					     		grabar_archivo(archivo,lista,num,4);
					     		break;

					    case 6:
					     		printf("\n Fin del programa... \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=6);				
										
			        break;					
			case 5: 
					printf("\nIngrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
			

					do{

					printf("\n\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea importar productos de un archivo de texto: \n");
					printf("5. Desea exportar productos a un archivo de  texto: \n");
					printf("6. Salir del programa: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								imprimirProductos(lista,num);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								cargar_archivo(archivo,lista,5);
								break;

					    case 5:
					     		grabar_archivo(archivo,lista,num,5);
					     		break;

					    case 6:
					     		printf("\n Fin del programa... \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=6);				
										
			        break;
			case 6: 
					printf("Fin del programa...\n");
					break;
			default:
            printf("opcion invalida\n");
            break;
		}

	}while(opcion!=6);

	lista=liberaMemoria(lista);

	return 0;

}

Producto* crearProducto(int num)
{
	Producto *lista = NULL;
	
	lista = (Producto *) calloc(num, sizeof(Producto));
	
	//Termina el programa en caso de no poder reservar la memoria.
	if(lista == NULL)
	{
		printf("\n\t>>  No se pudo reservar la memoria <<\n\tIntente ejecutar el programa más tarde.");
		fflush(stdin);
		getchar();
		exit(0);
	}
	
	return lista;
}

Producto* ingresarProducto(Producto *inicio,int num){
	Producto *produActual= inicio;
	
	int i=0;

	for (i = 0; i < num; ++i)
	{
		
	if (inicio== NULL)
	{
		produActual=malloc(sizeof(Producto));
		//produActual->valor=dato;
		produActual->sig=NULL;
		inicio=produActual;
	}else{
		while(produActual->sig != NULL){
			produActual=produActual->sig;
		}
		Producto *produNuevo= malloc(sizeof(Producto));
		//produNuevo->valor=dato;
		produNuevo->sig=NULL;
		produActual->sig=produNuevo;
	     }
    }
	return inicio;
}

void leerProducto(Producto *inicio, int num)
{
	int i; //Recorre el arreglo de estructuras.
	
	for(i=0; i<num; i++)
	{
		printf("\n");
		printf(">> Ingresa el nombre del producto %d: ",i+1);
		scanf(" %[^\n]",(inicio+i)->nombreProducto);
		printf(">> Ingresa el precio de producto %d: ",i+1);
		scanf(" %f",&(inicio+i)->precio);
		printf(">> Ingresa cuantos productos hay %d: ",i+1);
		scanf(" %d",&(inicio+i)->hay);
		/*printf(">> Ingresa cuantos se han vendido %d: ",i+1);
		scanf(" %[^\n]",(c+i)->vendidos);*/
	}
}

void imprimirProductos(Producto *inicio,int num){

	Producto *produActual=inicio;

	int i=0,conta=0;

	if (produActual==NULL)
	{
		printf("\nNo ha agregado ningun producto\n");
		exit(0);
	}

	printf("\nLos productos son: \n");

	while(produActual != NULL && conta<num){

			for (i = 0; i < num; ++i)
			{
				printf("\nNombre %d: %s, Precio %d: %.2f, Inventario %d: %d\n",i+1,(produActual+i)->nombreProducto,i+1,(produActual+i)->precio,i+1,(produActual+i)->hay);
				conta++;
			}
			produActual=produActual->sig;
			
	}
	printf("\n---------------\n");
}

Producto* liberaMemoria(Producto *inicio){
	if(inicio==NULL){
		return NULL;
	}
	Producto *produActual = inicio;
	Producto *produSig = inicio->sig;
	while(produSig != NULL){
		free(produActual);
		produActual = produSig;
	produSig = produActual->sig;
	}
	free(produActual);
	return NULL;
}

Producto* eliminarProducto(Producto *inicio, int indice){
	Producto *produActual = inicio;

	if(inicio==NULL){
		return NULL;
	}
	else if(indice == 0){
		produActual = inicio->sig;
		free(inicio);
		return produActual;
	}
	else{
		Producto *anterior = inicio;
		int i = 0;


		while(i<indice && produActual->sig != NULL){
			anterior = produActual;
			produActual = produActual->sig;
			i++;
		}
		anterior->sig = produActual->sig;
		free(produActual);
		if(i==0){
			return NULL;
		}
	}
	return inicio;
}

int obtenerProducto(Producto *inicio, int indice){
	Producto *produActual = inicio;
	int i = 0;
	if(inicio==NULL){
		return 0;
	}
	while(i<indice && produActual->sig != NULL){
		produActual = produActual->sig;
		i++;
	}
	return produActual->valor;
}

void grabar_archivo(FILE *archivo, Producto *inicio, int num, int opcion)
{
	int i;
	unsigned char nombre[25]= {'\0'};
	
	switch(opcion)
	{
		case 1:
			archivo = fopen("electronica.txt", "a+");
		break;
		case 2:
			archivo = fopen("papeleria.txt", "a+");
		break; 
		case 3:
			archivo = fopen("ropa.txt", "a+");
		break; 
		case 4:
			archivo = fopen("muebles.txt", "a+");
		break;
		case 5:
			archivo = fopen("deportes.txt", "a+");
		break; 
		default:
			printf("Easter Egg (*.*) \n");
		break;
	}	

	/*
	printf("\n\tEscribe el nombre del archivo en el cual deseas guardar\n\tlos productos con su extensión: \n\n\t\t>> Nombre: ");
	scanf(" %[^\n]",nombre);
	archivo = fopen(nombre,"w");
	*/

		for(i=0; i<num; i++)
		{
			fprintf(archivo,"%s %.2f %.2d\n",(inicio+i)->nombreProducto,(inicio+i)->precio,(inicio+i)->hay);
		}
		fclose(archivo);
	
}


void cargar_archivo(FILE *archivo, Producto *inicio, int opcion)
{
	int num;
	unsigned char nombre[30];
	int i; 
	switch(opcion)
	{
		case 1:
			archivo = fopen("electronica.txt", "r");
		break;
		case 2:
			archivo = fopen("papeleria.txt", "r");
		break; 
		case 3:
			archivo = fopen("ropa.txt", "r");
		break; 
		case 4:
			archivo = fopen("muebles.txt", "r");
		break;
		case 5:
			archivo = fopen("deportes.txt", "r");
		break; 
		default:
			printf("Easter Egg (*.*) \n");
		break;
	}
	
	num = contar_renglones(archivo);
	inicio = crearProducto(num);

	printf("\nLos productos son: ");

	for(i=0; i<num; i++){
		fscanf(archivo,"%s\t%s\t%s",(inicio+i)->nombreProducto,(inicio+i)->precioProdu,(inicio+i)->hayProdu);
		printf("\n\n>> Producto %d:\n",i+1);
		printf("\nNOMBRE %d: %s", i+1, (inicio+i)->nombreProducto);
		printf("\nPrecio %d: %s", i+1, (inicio+i)->precioProdu);
		printf("\nInventario %d: %s", i+1,(inicio+i)->hayProdu);
	}

	fclose(archivo);	
}


int contar_renglones(FILE *archivo)
{
	int num = 0;
	char c;
	
	while(feof(archivo) == 0)
	{
		c = fgetc(archivo);
		if(c == '\n')
			++num;
	}
	rewind(archivo);
		
	return num;
}