#include<stdio.h>
#include<stdlib.h>
#include<string.h>




struct doble{
	int dato;
	doble *sig,*ant;
};





struct doble *cab = NULL;



void insertar(int num);
void leer();



int main(){
	insertar(5);
	insertar(4);
	insertar(1);
	insertar(2);
	insertar(3);
	printf("lista: ");
	leer();
	
	return 0l;
}




void insertar(int num){
	struct doble *nv = (struct doble*)malloc(sizeof(struct doble));
	struct doble *aux = cab;
	
	nv->dato = num;
	nv->sig = NULL;
	nv->ant = NULL;
	
	if(aux == NULL){
		cab = nv;
		aux = NULL;
		free(aux);
	}else{
		if(aux->dato > nv->dato){
			cab = nv;
			nv->ant = aux;
			aux->sig = nv;
			aux = NULL;
			free(aux);
		}else{
			while(aux != NULL){
				if(aux->ant == NULL){
					aux->ant = nv;
					nv->sig = aux;
					aux = NULL;
				}else{
					if(aux->ant->dato > nv->dato ){
						nv->sig = aux;
						nv->ant = aux->ant;
						aux->ant = nv;
						aux->ant->sig = nv;
						aux = NULL;
					}else{
						aux = aux->ant;
					}
				}
				
			
			}
		}
		
	}
}






void leer(){
	struct doble *reco = cab;
	
	while(reco != NULL){
		printf("%i ",reco->dato);
		reco = reco->ant;
	}
}
