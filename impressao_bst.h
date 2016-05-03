#define TAB 30
#define SPACE 3

typedef struct tnodo {
    int chave;
    struct tnodo * pai;
    struct tnodo * esq;
    struct tnodo * dir;
} Tno;

void print_tab(int n){
    int i;
    for (i=0; i< n; i++){
        printf(" ");
    }
}

void imprime_andar(Tno**, int, int);
void imprime_formatado(Tno**, int);
void print_tab(int);


void imprime_andar(Tno** n, int i, int altura){
    Tno * aux;
    aux = (*n);
    if (aux == NULL)
        return;
    if (i == 0)
    {
            print_tab(TAB);
            printf("%d", aux->chave);
    }
    else if (i == 1)
    {
            print_tab(TAB/2);
            printf("%d", aux->esq->chave);

            print_tab(TAB);
            printf("%d", aux->dir->chave);
    }

    if (i == 2)
    {
        print_tab(TAB/4);
        aux=(*n)->esq;
        if (aux != NULL)
        {

            if (aux->esq != NULL)
                printf("%d", aux->esq->chave);
            else
                printf("NIL");
            print_tab(TAB/2);
            if (aux->dir != NULL)
            {
                printf("%d", aux->dir->chave);
            }
            else
                printf("NIL");
        }

        print_tab(TAB/2);
        aux=(*n)->dir;
        if (aux != NULL)
        {
            if (aux->esq != NULL)
            {
                printf("%d ", aux->esq->chave);
            }
            else
            {
                printf("NIL");
            }
            print_tab(TAB/2);
            
            if (aux->dir != NULL)
            {
                printf("%d ", aux->dir->chave);
            }
            else
            {
                printf("NIL");
            }
        }
    }
    
    if (i == 3)
    {
        print_tab(TAB/8);
        aux=(*n)->esq;
        aux=aux->esq;
        if (aux != NULL)
        {
            if(aux->esq != NULL)
                printf("%d ", aux->esq->chave);
            else
                printf("NIL");
            print_tab(TAB/8);
            if(aux->dir != NULL)
                printf("%d ", aux->dir->chave);
            else
                printf("NIL");
        }

        aux=(*n)->esq;
        aux=aux->dir;
        print_tab(TAB/4);
        
        if (aux != NULL)
        {
            if(aux->esq != NULL)
                printf("%d ", aux->esq->chave);
            else
                printf("NIL");
            print_tab(TAB/8);
            if(aux->dir != NULL)
                printf("%d ", aux->dir->chave);
            else
                printf("NIL");
        }

        aux=(*n)->dir;
        aux=aux->esq;
        print_tab(TAB/4);
        if (aux != NULL)
        {
            if(aux->esq != NULL)
                printf("%d ", aux->esq->chave);
            else
                printf("NIL");
            print_tab(TAB/8);
            if(aux->dir != NULL)
                printf("%d ", aux->dir->chave);
            else
                printf("NIL");
        }

        print_tab(TAB/4);
        aux=(*n)->dir;
        aux=aux->dir;
        if (aux != NULL)
        {
            if(aux->esq != NULL)
                printf("%d ", aux->esq->chave);
            else
                printf("NIL");
            print_tab(TAB/4);
            if(aux->dir != NULL)
                printf("%d ", aux->dir->chave);
            else
                printf("NIL");
        }
     }   
     


     printf("\n");
}

void imprime_formatado(Tno** n, int altura){
    int i = 0;
    while (i < altura){
        imprime_andar(n, i, altura);
        i++;
    } 
}
