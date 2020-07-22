#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    char nome[10];
}conteudoNo;

typedef  struct No{
    conteudoNo conteudo;
    struct No *ant;
    struct No *prox;
}no;

typedef struct{
    no *inicio;
    no *fim;
    no *atual;
}lista;

int vazia(lista l);
void inicia(lista *l);
void insere(lista *l, conteudoNo x);
void mostra(lista l);
void exclui(lista *l, int n);
void editar(lista *l, conteudoNo v);

int main()
{
    lista l;
    inicia(&l);
    lista h;
    inicia(&h);
    //mostra(l);
    conteudoNo v;
    fgets(v.nome, 10, stdin);
    v.num = 1;
    insere(&l, v);
    insere(&h, v);
    fgets(v.nome, 10, stdin);
    v.num = 2;
    insere(&l, v);
    insere(&h, v);
    fgets(v.nome, 10, stdin);
    v.num = 3;
    insere(&l, v);
    insere(&h, v);

    conteudoNo novo;
    printf("Digite o id para editar: ");
    scanf("%d", &novo.num);
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(novo.nome, 10, stdin);
    editar(&l, novo);
    insere(&h, novo);
   mostra(h);
    printf(" \n");
    //exclui(&l, 2);
    //mostra(l);
    return 0;
}

int vazia(lista l){
    if(l.inicio==NULL){
        return 1;
    }
    return 0;
}

void inicia(lista *l){
    l->inicio = NULL;
    return;
}

void insere(lista *l, conteudoNo x){
    no *aux;
    aux = (no*)malloc(sizeof(no));
    aux->conteudo = x;
    if(l->inicio==NULL){
        l->inicio = aux;
        l->fim=aux;
    }
    else{
        l->fim->prox=aux;
        aux->ant=l->fim;
        l->fim=aux;
    }
}

void mostra(lista l){
    if(vazia(l)){
        printf("Lista Vazia\n");
    }
    no *i;
    i=l.inicio;
    while(i){
        printf("%d, %s\n", i->conteudo.num, i->conteudo.nome);
        i=i->prox;
    }
}

void exclui(lista *l, int n){
    no *aux;
    aux=l->inicio;
    if(l->inicio->conteudo.num==n){
        l->inicio=aux->prox;
    }
    if(l->fim->conteudo.num==n){
        l->fim=NULL;
    }
    else{
        aux=aux->prox;
        while(aux!=NULL){
            if(aux->conteudo.num==n){
                aux->prox->ant=aux->ant;
                aux->ant->prox=aux->prox;
            }
            aux=aux->prox;
        }
    }
    free(aux);
}

void editar(lista *l, conteudoNo v){
    no *aux2;
    aux2 = l->inicio;
    while(aux2){
        if(aux2->conteudo.num==v.num){
            aux2->conteudo=v;
            return;
        }
        aux2=aux2->prox;
    }
    return;
}
