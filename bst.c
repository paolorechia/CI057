#include <stdio.h>
#include <stdlib.h>
#include "impressao_bst.h"

static void inicia_arvore(Tno ** arv, int chave){

	*arv=malloc(sizeof(Tno));
	(*arv)->chave = chave;
	(*arv)->pai = NULL;
    (*arv)->esq = NULL;
	(*arv)->dir = NULL;

	return;
}


Tno * insere (Tno ** n, int chave){
	if (chave < (*n)->chave){
		if ((*n)->esq != NULL)
			insere(&(*n)->esq, chave);
		else{
			(*n)->esq=malloc(sizeof(Tno));
			(*n)->esq->esq=NULL;
			(*n)->esq->dir=NULL;
			(*n)->esq->pai=(*n);
			(*n)->esq->chave=chave;
		}
	}
	else{
		if ((*n)->dir != NULL)
			insere(&(*n)->dir, chave);
		else{
			(*n)->dir=malloc(sizeof(Tno));
			(*n)->dir->esq=NULL;
			(*n)->dir->dir=NULL;
			(*n)->dir->pai=(*n);
			(*n)->dir->chave=chave;
		}
	}
	return *n;
}

static void em_ordem(Tno ** n){
	if ((*n) != NULL)
	{
		em_ordem(&(*n)->esq);
		printf("%d ", (*n)->chave);
		em_ordem(&(*n)->dir);
	}
	return;

}

static void pos_ordem(Tno ** n){
	if ((*n) != NULL)
	{
		pos_ordem(&(*n)->esq);
		pos_ordem(&(*n)->dir);
		printf("%d ", (*n)->chave);
	}
	return;
}
		
static void pre_ordem(Tno ** n){
	if ((*n) != NULL)
	{
		printf("%d ", (*n)->chave);
		pre_ordem(&(*n)->esq);
		pre_ordem(&(*n)->dir);
	}
	return;
}

void altura(Tno **n, int * max, int atual){
    if ((*n) != NULL)
    {
        atual++;
//        printf("atual %d\n", atual);
        if (atual > *max)
            *max=atual;
//            printf("maximo agora é %d\n", *max);
        altura(&(*n)->esq, max, atual);
        altura(&(*n)->dir, max, atual);
        atual--;
//        printf("atual %d\n", atual);
    }
}

int calcula_altura(Tno** n){
    int max = 0;
    int atual = 0;
    altura(n, &max, atual); 
    return max;
}


Tno * busca(Tno ** n, int chave){
	if ((*n) == NULL)
	{
		printf("Nao encontrado\n");
		return NULL;
	}
	else if (chave == (*n)->chave){
		return (*n);
	}
	if (chave < (*n)->chave)
		busca(&(*n)->esq, chave);
	
	else
		busca(&(*n)->dir, chave);
	
}


	


int main (){
	Tno * arv;
	Tno * nodo;
    int alt;
	inicia_arvore(&arv, 10);
    insere(&arv, 4);
    insere(&arv, 2);
    insere(&arv, 14);
    insere(&arv, 5);
    insere(&arv, 16);
    insere(&arv, 12);
    insere(&arv, 1);
    insere(&arv, 3);
	printf("Impressao em ordem:\n");
	em_ordem(&arv);
	putchar('\n');
	printf("Impressao pos ordem:\n");
	pos_ordem(&arv);
	putchar('\n');
	printf("Impressao pre ordem:\n");
	pre_ordem(&arv);
	putchar('\n');
	nodo = busca(&arv, 14);
	printf("%d\n", nodo->chave);
	nodo = busca(&arv, 8);
	if (nodo != NULL){
		printf("%d\n", nodo->chave);
	}
    int max = 0;
    int atual = 0;
    alt = calcula_altura(&arv);
    printf("Altura da arvore = %d\n", alt);
    imprime_formatado(&arv, alt);
	return 0;
}
