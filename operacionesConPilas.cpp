//                                  estucturas dinamicas pilas
#include<stdio.h>
#include<stdlib.h>


 
//declaracion de los structs
typedef int elemento;

typedef struct Nodo{
	elemento elem;
	struct Nodo *sgt;
}nodo;

typedef struct{
	nodo *tp;
}pila;
//fin de decalracion de stucts 



//prototipado
void creaPila(pila *p);
int comprobarSiPilaVacia(pila *p );
elemento devielveTope(pila *p);
void insertarElemetoPila(pila *p,elemento elem);
void eliminarUnNodo(pila *p);
void limpiarTodaLaPila(pila *tp);
int contadorDeNodosDePila(pila p);
int menuPrincipal();
//fin de decalracion de prototipado




int main(){
	pila p;
	int opc,n,cantNodos;
	opc = menuPrincipal();
	
	while(opc!=0){
		switch(opc){
			case 1:
				creaPila(&p);
				printf("\nSe creo una pila\n");
				system("pause");
			break;
			case 2:
				printf("\nIngrese el elemento que desee guardar: ");
				scanf("%i",&n);
				while(n != 0){
					insertarElemetoPila(&p,n);
					printf("\nSe a insetado el elemento %i correctamente.\n",n);
					printf("\nIngrese otro elemento que desee guardar: ");
					scanf("%i",&n);
				}
				system("pause");
			break;
			case 3: 
				eliminarUnNodo(&p);
				printf("\nSe a se a eliminado corrctamentre el primer elemento de la pila.\n");
				system("pause");
			break;
			case 4:
				cantNodos = contadorDeNodosDePila(p);
				printf("\nLa pila tiene %i elementos\n",cantNodos);
				system("pause");
			break;
			case 5:
				limpiarTodaLaPila(&p);
				cantNodos = contadorDeNodosDePila(p);
				printf("\nLa pila se a limpiado correctamente. Ahora tiene %i\n",cantNodos);
				system("pause");
			break;
			case 6:
				printf("\nEl elemento de la cima es %i\n",devielveTope(&p));
				system("pause");
			break;
			default:
				printf("No existe La opcion ingresada.");
				system("pause");
			break;	
		}
		opc = menuPrincipal();
	}
	
	
	return 0;
}


//Creacion de pila
void creaPila(pila *p){
	p->tp=NULL;
}


//comprueba si pila esta vacia 
int comprobarSiPilaVacia(pila *p ){
	return (p->tp == NULL); //devuelve 1 si es verdadero, devuelve 0 si es falso
}


//rotornar el tope de pila
elemento devielveTope(pila *p){
	if(comprobarSiPilaVacia(p)){
		printf("La pila esta vacia\n");
		exit(1);
	}else{
		return p->tp->elem;
	}
}


//insertar un elemeto a al pila
void insertarElemetoPila(pila *p,elemento elem){
	nodo *nuevo;
	nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->elem = elem;
	nuevo->sgt=p->tp;
	p->tp=nuevo;
}


//eliminar un elemento de la pila
void eliminarUnNodo(pila *p){
	if(comprobarSiPilaVacia(p)==0){
		nodo *f;
		f=p->tp;
		p->tp=f->sgt;
		free(f);
		printf("\nSe elimino correctamente el primer elemento de la pila\n");
	}else{
		printf("\nLa pila esta vacia");
	}
}


//limpiar toda la pila
void limpiarTodaLaPila(pila *p){
	while(!comprobarSiPilaVacia(p)){
		eliminarUnNodo(p);
	}
}


//contar cantidad de elemetos de pila
int contadorDeNodosDePila(pila p){
	nodo *act;
	int cantElem = 0;
	for(act = p.tp ;act != NULL;act = act->sgt){
		cantElem++;
	}
	return cantElem;
}

int menuPrincipal(){
	system("cls");
	printf("\n*******************PILAS*****************\n");
	
	int op;
	
	printf("\n1.Crear Pila.");
	printf("\n2.Ingresar un elemeto a la Pila.");
	printf("\n3.Eliminar el tope de la pila.");
	printf("\n4.Ver tamanio de la pila.");
	printf("\n5.Limpiar toda la pila.");
	printf("\n6.Ver el tope de pila.");
	printf("\n0.Cerrar programa");
	printf("\n\nIngrese una opcion: ");
	scanf("%i",&op);
	
	return op;
}