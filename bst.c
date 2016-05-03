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
        if ((*n)->esq != NULL)
            altura(&(*n)->esq, max, atual);
        if ((*n)->dir != NULL)
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


Tno * minimo(Tno ** n){
   if ((*n)->esq == NULL)
        return (*n);
   else minimo(&(*n)->esq); 
}

Tno * maximo(Tno ** n){
    if ((*n)->dir == NULL)
        return (*n);
    else maximo(&(*n)->dir);
}

Tno * sucessor(Tno * n){
    Tno * aux;
    if (n->dir != NULL)
        return (minimo(&n->dir));
    aux=n->pai; 
    while (aux != NULL && n == aux->dir){
        n=aux;
        aux=aux->pai;
    }
    return aux;
}


Tno * antecessor(Tno * n){
    Tno * aux;
    if (n->esq != NULL)
        return maximo(&n->esq);
    aux = n->pai;
    while (aux != NULL && n == aux->esq){
        n = aux;
        aux = aux->pai;
    }
    return aux;
}

Tno * remove(Tno ** n){
    if ((*n)->dir == NULL && (*n)->esq == NULL) // nenhum filho
    {
        if (n->pai->esq = (*n))
            n->pai->esq = NULL;
        else
            n->pai->dir = NULL;
        free(*n);
        return;
    }
    if (*n->esq == NULL && (*n)->dir != NULL) // filho à direita
    {
        *n->chave=*n->dir->chave;
        free(*n->dir);
        *n->dir = NULL;
    }
    if (*n-> dir == NULL && (*n)->esq != NULL) // filho à esquerda
    {
        *n->chave=*n->esq->chave;
        free(*n->esq);
        *n->esq = NULL;
    }
    if (*n->dir != NULL && (*n)->esq != NULL) // quarto caso, dois filhos
    {
        Tno * aux;
        if (*n->dir->esq == NULL)
        {
            
            
            
            
            
        

    
    
    
    
void insere_e_imprime(Tno **n, int chave){
    int alt;
    insere(n, chave);
    alt=calcula_altura(n);
    printf("Altura da arvore = %d\n", alt);
    imprime_formatado(n, alt);
    putchar('\n');
}

	


int main (){
	Tno * arv;
	Tno * nodo;
    int alt;
	inicia_arvore(&arv, 5);
    alt = calcula_altura(&arv);
    printf("Altura da arvore = %d\n", alt);
    imprime_formatado(&arv, alt);
    
    insere_e_imprime(&arv, 9);
    insere_e_imprime(&arv, 7);
    insere_e_imprime(&arv, 4);
    insere_e_imprime(&arv, 12);
    insere_e_imprime(&arv, 15);
    insere_e_imprime(&arv, 11);


	printf("Impressao em ordem:\n");
	em_ordem(&arv);
	putchar('\n');
	printf("Impressao pos ordem:\n");
	pos_ordem(&arv);
	putchar('\n');
	printf("Impressao pre ordem:\n");
	pre_ordem(&arv);
	putchar('\n');
    nodo = minimo(&arv);
    printf("Minimo: %d\n", nodo->chave);
    nodo = maximo(&arv);
    printf("Maximo: %d\n", nodo->chave);
    nodo = sucessor(arv);
    while (nodo != NULL){
        printf("Sucessor: %d\n", nodo->chave);
        nodo = sucessor(nodo);
    } 
    nodo = antecessor(arv);
    while (nodo != NULL){
        printf("Antecessor: %d\n", nodo->chave);
        nodo = antecessor(nodo);
    } 
	return 0;
}
