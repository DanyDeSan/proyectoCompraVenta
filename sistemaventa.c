#include <locale.h> //setlocale
#include <stdio.h> //printf, scanf
#include <stdlib.h> //calloc, exit
#include <string.h> //strlen

//Estructura para los contactos:
typedef struct producto
{
	int valor;
	unsigned char nombreProducto[30];
	float precio;
	unsigned int hay;
	struct producto *sig;

}Producto;



//Prototipos de funciones a utilizar:
void desplegarMenuDepartamento(int departamento);
Producto* introducirProductos();
Producto* crearProducto(int num);
Producto* ingresarProducto(Producto *inicio,int num);
void leerProducto(Producto *inicio, int num);
void imprimirProductos(Producto *inicio);
Producto* liberaMemoria(Producto *inicio);
Producto* eliminarProducto(Producto *inicio, int indice);
int obtenerProducto(Producto *inicio, int indice);
Producto* Push(Producto *inicio, int v);
int Pop(Producto *inicio);

//http://disi.unal.edu.co/~lctorress/estructuras/pdf/EInf99.pdf
//void grabar_archivo(FILE *archivo, struct contacto *c, int num);

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL,"Spanish_Mexico");

	FILE *archio=NULL;
	Producto *lista=NULL;
	int num=0,i=0, opcion=0,indice=0,obtener;


	do{
		//cabecera();//para que se bonito letrero de la tienda

		printf("\nOpciones de la Tienda: \n\n");
		printf("1. Departamento de electronica. \n");
		printf("2. Departamento comida. \n");
		printf("3. Departamento ropa. \n");
		printf("4. Departamento muebles. \n");
		printf("5. Departamento deportes. \n");
		printf("6. Salir del programa\n\n");

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
					lista=Push(lista,num);

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea Regresar: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								printf("\nLos productos son: \n");
								imprimirProductos(lista);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								imprimirProductos(lista);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								printf("\n Menu anterior: \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=4);				
										
			        break;
      		case 2:
      				printf("Ingrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					lista=Push(lista,num);

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea Regresar: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								printf("\nLos productos son: \n");
								imprimirProductos(lista);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								imprimirProductos(lista);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								printf("\n Menu anterior: \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=4);				
										
			        break;					
      		case 3:
            		printf("Ingrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					lista=Push(lista,num);

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea Regresar: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								printf("\nLos productos son: \n");
								imprimirProductos(lista);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								imprimirProductos(lista);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								printf("\n Menu anterior: \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=4);				
										
			        break;
            case 4:
            		printf("Ingrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					lista=Push(lista,num);

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea Regresar: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								printf("\nLos productos son: \n");
								imprimirProductos(lista);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								imprimirProductos(lista);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								printf("\n Menu anterior: \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=4);				
										
			        break;					
			case 5: 
					printf("Ingrese el numero de productos\n");
					scanf("%d",&num);
					lista=crearProducto(num);
					lista=ingresarProducto(lista,num);				
					leerProducto(lista,num);
					lista=Push(lista,num);

					do{

					printf("\nIngrese una opcion: \n\n");
					printf("1. Desea mostrar la lista de productos: \n");
					printf("2. Desea eliminar algun producto: \n");
					printf("3. Desea modificar algun producto: \n");
					printf("4. Desea Regresar: \n\n");

					opcion=0;
					printf("Su opcion es: ");
					scanf("%d",&opcion);

					switch(opcion)
						{
						case 1:
								printf("\nLos productos son: \n");
								imprimirProductos(lista);
								break;

						case 2: 
								printf("\nIngrese el indice del producto a eliminar: \n");
								scanf("%d",&indice);
								lista=eliminarProducto(lista,indice);
								imprimirProductos(lista);
								break;

						case 3: 
								indice=0;
								printf("\nIngrese el indice del producto a modificar: \n");
								scanf("%d",&indice);
								indice=obtenerProducto(lista,indice);
								break;

						case 4:
								printf("\n Menu anterior: \n");
					            break;
						default:
            			printf("opcion invalida\n");
            			break;


						}

					}while(opcion!=4);				
										
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
	struct producto *lista = NULL;
	
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
		//produActual->departa="electronica";
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

void imprimirProductos(Producto *inicio){
	Producto *produActual = inicio;
	int i =0;
	while(produActual != NULL){
			printf("%d:\t%s\n",i+1,produActual->nombreProducto);
			produActual = produActual->sig;
 		}
	printf("---------------\n");
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

Producto* Push(Producto *inicio, int v)
{
    Producto *pNodo= inicio;
   /* Crear un nodo nuevo */
   pNodo = malloc(sizeof(Producto));
   pNodo->valor = v;
   /* Añadimos la pila a continuación del nuevo nodo */
   pNodo->sig = inicio;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   inicio = pNodo;
   return pNodo;
}

int Pop(Producto *inicio)
{
   Producto *pNodo=inicio; /* variable
 auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   /* Nodo apunta al primer elemento de la pila */
   pNodo = inicio;
   if(!pNodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a pila toda la 
pila menos el primer elemento */
   inicio = pNodo->sig;
   /* Guardamos el valor de retorno */
   v = pNodo->valor; 
   /* Borrar el nodo */
   free(pNodo);
   return v;
}
//Funcion que se encarga de desplegar el menu de cada departamento
void desplegarMenuDepartamento(int departamento)
{
	Producto *lista=NULL;
	int num=0,i=0, opcion=0,indice=0,obtener;
	printf("\nIngrese el numero de productos: ");
	scanf("%d",&num);
	lista=crearProducto(num);
	lista=ingresarProducto(lista,num);				
	leerProducto(lista,num);
	lista=Push(lista,num);

	do{

	printf("\nIngrese una opcion: \n\n");
	printf("1. Ingresar nuevos productos\n");
	printf("2. Desea mostrar la lista de productos: \n");
	printf("3. Desea eliminar algun producto: \n");
	printf("4. Desea modificar algun producto: \n");
	printf("5. Desea Regresar: \n\n");


	opcion=0;
	printf("Su opcion es: ");
	scanf("%d",&opcion);

	switch(opcion)
	{
		case 1:
		//Aqui van las funciones para ingresar nuevos productos. 
		break;

		case 2: 
			printf("\nLos productos son: \n");
			imprimirProductos(lista);
		break;

		case 3: 
			printf("\nIngrese el indice del producto a eliminar: \n");
			scanf("%d",&indice);
			lista=eliminarProducto(lista,indice);
			imprimirProductos(lista);
		break;

		case 4:
			indice=0;
			printf("\nIngrese el indice del producto a modificar: \n");
			scanf("%d",&indice);
			indice=obtenerProducto(lista,indice);
		break;
		case 5:
			printf("\n Menu anterior: \n");
		break; 
		default:
        printf("opcion invalida\n");
        break;
	}

	}while(opcion!=4);
}