#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaracion de campos de las pilas
typedef struct Nodo{
	int numero;
	Nodo *sgt;
}nodo;

typedef struct{
	nodo *tp1=NULL, *tp2=NULL, *tp3=NULL;
}pila;

//prototipado
void cargarPila(pila *p);
void leerPila(pila p,int cual);
void movimientos(pila *p, int desde, int asia);
int contadorDeNodosDePila(pila p, int cual);
//void borrar(pila *p,int cual);
//void inicializar(pila *p,int cual);
int retornarTope(pila *p, int cual);
int comprobarSiPilaVacia(pila *p, int cual);
void insertarElemetoPila(pila *p,int elem, int cual);
void eliminarTope(pila *p, int cual);
void funcionCambio(pila *p);
int menu();



int main(){
	int opc,i=1,i2;
	pila p;
	int algo;
	
	opc=menu();
	while(opc != 0){
		switch(opc){
			case 1:
				cargarPila(&p);
				printf("\nSe ha cargado correctamente la pila.\n");
				system("pause");
			break;
			case 2:
				printf("\nQue pila desea leer? \n");
				scanf("%i",&algo);
				leerPila(p,algo);
				system("pause");
			break;
			case 3:
//					mueve el primero a la tercera
					movimientos(&p,1,3);
					printf("\nSe movio correctamente el primero a la tercera\n");
					system("pause");
							
//					mueve lo que quedo en la pila 1 a la pila 2		
					i2=contadorDeNodosDePila(p,1);
					while(i<=i2){
						movimientos(&p,1,2);
						i++;
					}
					printf("\nSe movio cerrectamente el resto al segudo\n");
					system("pause");

//					mueve el unico que esta en la pila 3 a la pila 1 
					movimientos(&p,3,1);
					printf("\nSe movio correctamente el tercero a la primera\n");
					system("pause");

//					mueve el primero de la pila 2 a la tercera
					movimientos(&p,2,3);
					printf("\nSe movio correctamente el primero del segundo al tercero\n");
					system("pause");

//					mueve todos los que quedaron a la primer pila
					i=1;
					i2=contadorDeNodosDePila(p,2);
					while(i<=i2){
						movimientos(&p,2,1);
						i++;
					} 
					printf("\nSe movio correctamente todos los que quedaban en el segundo a la primera\n");
					system("pause");

//					mueve el que esta solo en la tercer pila a la primera
					movimientos(&p,3,1);
					printf("\nSe movio correctamente el de la tercera a la 1ra\n");
					system("pause");

			break;
			case 9:
				printf("\nQue pila desea comprobar si esta vacia? \n");
				scanf("%i",&algo);
				algo=comprobarSiPilaVacia(&p,algo);
				printf("\nPila tiene el valor de: %i\n",algo);
				system("pause");
			break;
			case 10:
				printf("\nQue pila desea eliminar el tope? \n");
				scanf("%i",&algo);
				eliminarTope(&p,algo);
			break;
			default:
				printf("\nNo existe la opcion ingresada\n");
				system("pause");
			break;
		}
		opc=menu();
	}
	
	return 0;
}
//----------------------------------------------------------------------------------

//carga de nodos a la pila
void cargarPila(pila *p){
	int e;
	
	printf("\nIngres el elemento que desea apilar o \"0\" para salir: ");
	scanf("%i",&e);
	while(e!=0){
		insertarElemetoPila(p,e,1);
		printf("\nIngres el elemento que desea apilar o \"0\" para salir: ");
		scanf("%i",&e);
	}
}
//----------------------------------------------------------------------------------


//lee cada componente la pila
void leerPila(pila p,int cual){
	nodo *ncontador;
	int queEs;
	int cantElem = 0;
	
	switch(cual){
		case 1:
			printf("Pila1:\n");
			for(ncontador = p.tp1 ;ncontador != NULL;ncontador = ncontador->sgt){
				queEs=ncontador->numero;
				printf("\t%i\n",queEs);
			}
		break;
		case 2:
			printf("Pila2:\n");
			for(ncontador = p.tp2 ;ncontador != NULL;ncontador = ncontador->sgt){
				queEs=ncontador->numero;
				printf("\t%i\n",queEs);
			}
		break;
		case 3:
			printf("Pila3:\n");
			for(ncontador = p.tp3 ;ncontador != NULL;ncontador = ncontador->sgt){
				queEs=ncontador->numero;
				printf("\t%i\n",queEs);
			}
		break;
	}
}
//----------------------------------------------------------------------------------



//procedimiento para mover los nodos entre las pilas
void movimientos(pila *p, int desde, int asia){
	int elem;
	
	elem = retornarTope(p,desde);
	eliminarTope(p,desde);
	insertarElemetoPila(p, elem,asia);
}
//----------------------------------------------------------------------------------



//borra el nodo
//void borrar(pila *p, int cual){
//	switch(cual){
//		case 1:
//			free(p->tp1);
//		break;
//		case 2:
//			free(p->tp2);
//		break;
//		case 3:
//			free(p->tp3);
//		break;
//	}
//}




//contar cantidad de elemetos de pila
int contadorDeNodosDePila(pila p, int cual){
	nodo *ncontador;
	int cantElem = 0;
	
	switch(cual){
		case 1:
			for(ncontador = p.tp1 ;ncontador != NULL;ncontador = ncontador->sgt){
				cantElem++;
			}
		break;
		case 2:
			for(ncontador = p.tp2 ;ncontador != NULL;ncontador = ncontador->sgt){
				cantElem++;
			}
		break;
		case 3:
			for(ncontador = p.tp3 ;ncontador != NULL;ncontador = ncontador->sgt){
				cantElem++;
			}
		break;
	}
	return cantElem;
}
//----------------------------------------------------------------------------------



//volver a inicializar pila
//void inicializar(pila *p, int cual){
//	switch(cual){
//		case 1:
//			p->tp1=NULL;
//		break;
//		case 2:
//			p->tp2=NULL;
//		break;
//		case 3:
//			p->tp3=NULL;
//		break;
//	}
//}
//----------------------------------------------------------------------------------





//retorna tope de la pila indicada
int retornarTope(pila *p, int cual){
	
	if(cual == 1){
		if(comprobarSiPilaVacia(p,cual )){
			printf("\nLa pila esta vacia.");
			return 0;
		}
		else{
			return (p->tp1->numero);
		}
	}
	if(cual == 2){
		if(comprobarSiPilaVacia(p,cual )){
			printf("\nLa pila esta vacia.");
			return 0;
		}
		else{
			return (p->tp2->numero);
		}
	}
	if(cual == 3){
		if(comprobarSiPilaVacia(p,cual )){
			printf("\nLa pila esta vacia.");
			return 0;
		}
		else{
			return (p->tp3->numero);
		}
	}
}
//----------------------------------------------------------------------------------






//comprueba si la pila indicada esta vacia
int comprobarSiPilaVacia(pila *p, int cual ){
	switch(cual){
		case 1:
			return (p->tp1 == NULL); //devuelve 1 si es verdadero, devuelve 0 si es falso
		break;
		case 2:
			return (p->tp2 == NULL); //devuelve 1 si es verdadero, devuelve 0 si es falso
		break;
		case 3:
			return (p->tp3 == NULL); //devuelve 1 si es verdadero, devuelve 0 si es falso
		break;

	}
}
//----------------------------------------------------------------------------------



//procedimiento para ingresar elementos
void insertarElemetoPila(pila *p,int elem, int cual){
	nodo *nuevo;
	
	switch(cual){
		case 1:
			
			nuevo = (nodo*)malloc(sizeof(nodo));
			nuevo->numero = elem;
			nuevo->sgt=p->tp1;
			p->tp1=nuevo;
			
		break;
		case 2:
			
			nuevo = (nodo*)malloc(sizeof(nodo));
			nuevo->numero = elem;
			nuevo->sgt=p->tp2;
			p->tp2=nuevo;
			
		break;
		case 3:
			
			nuevo = (nodo*)malloc(sizeof(nodo));
			nuevo->numero = elem;
			nuevo->sgt=p->tp3;
			p->tp3=nuevo;
			
		break;
	}

}
//----------------------------------------------------------------------------------




//elimina el tope de la pila indicada
void eliminarTope(pila *p,int cual){
	if(comprobarSiPilaVacia(p,cual)){
		printf("\nLa pila ya esta vacia\n");
		
	}
	else{
		if(cual == 1){
			nodo *nuevo;
			nuevo = p->tp1;
			p->tp1=nuevo->sgt;
			free(nuevo);
		}
		if(cual == 2){
			nodo *nuevo;
			nuevo = p->tp2;
			p->tp2=nuevo->sgt;
			free(nuevo);
		}
		if(cual == 3){
			nodo *nuevo;
			nuevo = p->tp3;
			p->tp3=nuevo->sgt;
			free(nuevo);
		}
		
	}
	
}
//----------------------------------------------------------------------------------




//menu
int menu(){
	int op;
	
	printf("\t\t\t\t\tcambio el primero por el ultimo\n\n");
	printf("1-Ingresar elementos en la pila.\n");
	printf("2-Mostrar Elementos de la pila.\n");
	printf("3-Cambiar el primero por el ultimo.\n");
	printf("0-Salir.\n");
	printf("Opcion: ");
	scanf("%i",&op);
	
	return op;
}
//----------------------------------------------------------------------------------