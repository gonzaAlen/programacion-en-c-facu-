#include<stdio.h>
#include<stdlib.h>

//declaracion de la estructura de mi pila
typedef struct Nodo{
	int elemento;
	struct Nodo *sgt;
}nodo;

//declaracion de la pila

typedef struct{
	nodo *tp=NULL;
}pila;


//declaracion de los prototipados
//void crearPila(pila *p);
void cargarPila(pila *p, int elemen);
int leerPila(pila p);
int menu();


int main(){
	pila p;
	int op,elem,cantElem=0;
	
	op=menu();
	while(op!=0){
		switch(op){
//		case 1:
//			crearPila(&p);
//			printf("\nSe ha creado correctamente la pila.\n");
//			system("pause");
		break;	
		case 2:
			printf("\nIngrese el elemento que desea incluir en la pila  o 0 para salir: ");
			scanf("%i",&elem);
			while(elem != 0){
				cargarPila(&p,elem);
				printf("\nEl elemento se ingreso correctamente a la pila.\n");
				printf("\nIngrese el elemento que desea incluir en la pila  o 0 para salir: ");
				scanf("%i",&elem);			
			}
			system("pause");
		break;
		case 3:
			cantElem=leerPila(p);
			printf("\nLa pila tiene %i elementos.\n",cantElem);
			system("pause");
		break;
		default:
			printf("\nOpcion incorrecta.\n");
			system("pause");
		break;
		}
		op=menu();
	}
	
	
	return 0;
}

//crea una pila
//void crearPila(pila *p){
//	p->tp=NULL;
//}

//carga de pila
void cargarPila(pila *p, int elemen){
	nodo *nuevo;
	
	nuevo=(nodo*)malloc(sizeof(nodo));
	nuevo->elemento=elemen;
	nuevo->sgt=p->tp;
	p->tp=nuevo;
}

//contar cantidad de elemento ingresados
int leerPila(pila p){
	nodo *ncontador;
	int queEs;
	
	int cantElem = 0;
	for(ncontador = p.tp ;ncontador != NULL;ncontador = ncontador->sgt){
		cantElem++;
		queEs=ncontador->elemento;
		printf("\nEl elemento %i es: %i",cantElem,queEs);
	}
	return cantElem;
}

//menu principal
int menu(){
	system("cls");
	int op;
	
	printf("\t\t\t\t\tEjercicio 1 de plias\n");
	
	printf("ingrese la operacion que desea realizar o 0 para salir:\n");
	printf("1-Crear pila.\n");
	printf("2-Ingresar un elemento a la pila.\n");
	printf("3-Cantidad de elementos de la pila.\n");
	printf("Opcion: ");
	scanf("%i",&op);
	
	return op;
}
