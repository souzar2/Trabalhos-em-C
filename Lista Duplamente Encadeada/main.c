#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char nome[20];
}conteudoNo;

typedef struct No{
    struct No *anterior;
    struct No *proximo;
    conteudoNo atual;
}no;

typedef struct {
    no *fim;
    no *inicio;
}lista;

void inicia(lista *l);
void insere(lista *l, conteudoNo x);
void mostra(lista l);
int vazia (lista l);

int main()
{
    lista l;
    inicia(&l);
    mostra(l);
    conteudoNo v;
    v.n=1;
    v.nome[20]="Arthur";
    insere(&l, v);
    v.n=2;
    v.nome[20]="UFT";
    insere(&l, v);
    v.n=3;
    v.nome[20]="Palmas";
    insere(&l, v);
    mostra(l);
    system("PAUSE");
    printf("Hello world!\n");
    system("PAUSE");
    return 0;
}

int vazia(lista l){
    if(l.inicio==NULL){
        return 1;
    }
    return 0;
}

void inicia(lista *l){
    l->inicio=NULL;
}

void insere(lista *l, conteudoNo x){
    no *aux;
    aux=(no*)malloc(sizeof(no));
    aux->atual=x;
    if(vazia(*l)){
        l->inicio=aux;
        l->fim=aux;
    }else{
        l->fim->proximo=aux;
        aux->anterior=l->fim;
        l->fim=aux;
    }
}

void mostra(lista l){
    if(vazia(l)){
        printf("Lista Vazia");
      return;
    }
    no *i;
    i=l.inicio;
    while(i!=NULL){
        printf("%d, %s\n", i->atual.n, i->atual.nome);
        i=i->proximo;
    }
    return;
}
