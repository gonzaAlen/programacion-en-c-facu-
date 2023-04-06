#include <stdio.h>
#include <stdlib.h>


//declaracion de campos de los nodos
typedef struct Nodo{
	float monto;
	long documento;
	Nodo *sgt;
}nodo;

typedef struct{
	nodo *tp=NULL;
}sueldo;
//------------------------------------------------------------


//prototipado
void ingesoSeEmpleados(sueldo *s);//cargarPila(pila *p)
void insertarEnPila(sueldo *s, long dni, float pp);//void insertarElemetoPila(pila *p,int elem, int cual);
float calculoDeMonto(sueldo s, long dni);
void leerEmpleados(sueldo s);
int menu();
//------------------------------------------------------------



int main(){
	int opc;
	sueldo s;
	long doc;
	float dinero;
	
	opc = menu();
	while(opc!=0){
			switch(opc){
				case 1:
					ingesoSeEmpleados(&s);
					printf("\nSe ingreso correctamente datos del empleado\n");
					system("pause");
				break;
				case 2:
					printf("\nIngrese el documento\n");
					scanf("%i",&doc);
					dinero = calculoDeMonto(s, doc);
					printf("\nEl empleado de DNI: %i cobra: %.2f\n",doc,dinero);
					system("pause");
				break;
				case 3:
					leerEmpleados(s);
					system("pause");
				break;
			}
			opc = menu();
	}
	
	return 0;
}
//------------------------------------------------------------





//ingreso de datos de lso empleados a la pila
void ingesoSeEmpleados(sueldo *s){
	float plata;
	long nn;
	
	printf("\nIngrese el DNI del empleado o \"0\" para salir: ");
	scanf("%i",&nn);
	if(nn!=0){
		printf("\nIngrese el monto: ");
		scanf("%f",&plata);
		while(nn!=0){
			insertarEnPila(s,nn,plata);
			printf("\nIngrese el DNI del empleado o \"0\" para salir: ");
			scanf("%i",&nn);
			if(nn!=0){
				printf("\nIngrese el monto: ");
				scanf("%f",&plata);
			}
		}
	}
}
//------------------------------------------------------------





//carga en la pila los datos del empleado
void insertarEnPila(sueldo *s, long dni, float pp){
	nodo *nv;
	nv = (nodo*)malloc(sizeof(nodo));
	if(nv!=NULL){
		nv->monto = pp;
		nv->documento = dni;
		nv->sgt = s->tp;
		s->tp = nv;
	}else{
		printf("\nError.\n");
	}
	
}
//------------------------------------------------------------


//busca en la pila el empleado indicado
float calculoDeMonto(sueldo s, long dni){
	nodo *Ncont;
	float monto=0;
	
	for(Ncont = s.tp ;Ncont != NULL;Ncont = Ncont->sgt){
		if(Ncont->documento==dni){
			monto+=Ncont->monto;
		}
	}
	return monto;
}
//------------------------------------------------------------



//lee todos los empleados cargados
void leerEmpleados(sueldo s){
	nodo *Ncont;
	long queEs;
	float cuanto;
	
	for(Ncont = s.tp ;Ncont != NULL;Ncont = Ncont->sgt){
		queEs=Ncont->documento;
		cuanto = Ncont->monto;
		printf("\nEl empleado %i cobra: %.2f",queEs,cuanto);
	}
}
//------------------------------------------------------------




//menu principal
int menu(){
	int op;
	
	system("cls");
	printf("\n\t\t\t\t\tCalculo de sueldo de un personal\n");
	printf("\n1-Cargar personal.");
	printf("\n2-Calcular sueldo.");
	printf("\nOpciones: ");
	scanf("%i",&op);
	
	return op;
}
//------------------------------------------------------------