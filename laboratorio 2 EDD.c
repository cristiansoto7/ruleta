#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include "colas.h"


typedef struct nodo{
	int dato;
	struct nodo *sig;
}Nodo;

typedef struct cola{
	Nodo *ini;
	Nodo *fin;
	int tam;
}Cola;

typedef struct ruleta{
	Cola *rul;
	int tam;
}Ruleta;


Cola *crear_cola(){
	Cola *c;
	if(c=(Cola*)malloc(sizeof(Cola))){
		c->ini=NULL;
		c->fin=NULL;
		c->tam=0;
	}else{
		printf("error memoria no asignada en cola\n");
	}
	return c;
}

void encolar(Cola *col, int val){
	Nodo *new_nodo;
	if(new_nodo=(Nodo*)malloc(sizeof(Nodo))){
		
		if(col->tam==0){
			col->ini=new_nodo;
		}else{
			col->fin->sig=new_nodo;
		}
		new_nodo->sig=NULL;
		new_nodo->dato=val;
		col->tam++;
	}else{
		printf("Error memoria asignada nodo\n");
		free(new_nodo);
	}
}

int *frente(Cola *c){
	int frente;
	frente=c->ini->dato;
	return frente;
}

int desdencolar(Cola *col){
	int valor;
	if(col->tam==0){
		printf("la cola esta vacia");
	}else{
		Nodo *aux;
		aux=col->ini;
		valor=aux->dato;
		col->ini=aux->sig;
		col->tam--;
		free(aux);
	}
	return valor;
}

void imprimir(Cola *col){
	Nodo *aux;
	aux=col->ini;
	if(col->tam==0){
		printf("la cola esta vacia\n");
	}else{
		while(col->fin==NULL){
			printf("%d\n",aux->dato);
			aux=aux->sig;
		}
	}
}

Ruleta *crear_ruleta(){
	Ruleta *r;
	r->rul->ini=NULL;
	r->rul->fin=NULL;
	r->rul->tam=0;
	
	return r;
}

int main(){
	srand(time(0));
	Ruleta *la_ruleta;
	la_ruleta=crear_ruleta();
	while(la_ruleta->rul->tam!=10){
		encolar(la_ruleta->rul,10);
	}
	imprimir(la_ruleta->rul);
	return 0;
}
