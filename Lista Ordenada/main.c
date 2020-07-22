#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char nome[20];
}conteudoNo;

typedef struct No{
    struct No *ant;
    struct No *prox;
    conteudoNo atual;
}no;

typedef struct {
    no *inicio;
}lista;

void inicia(lista *l);
void insere(lista *l, conteudoNo v);
void mostra(lista l);

int main()
{
    printf("Hello world!\n");
    return 0;
}


void inicia(lista *l){
    l->inicio=NULL;
    return;
}

void insere(lista *l, conteudoNo v){
    no *aux;
    aux=(no*)malloc(sizeof(no));
    aux->atual=v;
    if(l->inicio==NULL){
        l->inicio=aux;
        return;
    }
        if(aux->atual.n<l->inicio->atual.n){
            aux->prox=l->inicio;
            l->inicio=aux;
            return;
        }
            no *aux2;
            aux2 = l->inicio;
            if(aux2){
                while(aux2->prox->atual.n<v.n){

                }
            }
        }
