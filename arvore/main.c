#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No *dir;
    struct No *esq;
    int n;
}no;

void cria(no **raiz);
int vazia(no *raiz);
void insere(no **raiz, int v);
int nivel(no **raiz, int v);
int pai(no **raiz, no b);

int main()
{
    no *raiz;
    no p;
    no aux;
    cria(&raiz);
    int op;
    int n;
    int repetir=1;
    printf("Os numeros maiores vao para a direita e os menores vao para a esquerda\n");
    while(repetir==1){
    printf("-------------------------------------------------------------------------\n");
    printf("1-Adicionar\n");
    printf("2-Verificar se esta vazia\n");
    printf("3-Nivel de algum no\n");
    printf("4-Nivel do pai de algum no\n");
    printf("5-Tamanho\n");
    scanf("%d", &op);
    switch(op){
    case 1:
        printf("Digite o numero que sera adicionado: ");
        scanf("%d", &n);
        insere(&raiz, n);
        break;
    case 2:
        if(vazia(&(*raiz))){
            printf("A arvore esta vazia\n");
        }
        else{
            printf("A arvore nao esta vazia\n");
        }
        break;
    case 3:
        printf("Digite o numero de algum no para verificar o seu nivel: ");
        scanf("%d", &n);
        printf("Nivel: %d\n", nivel(&(*raiz), n));
        break;
    case 4:
        printf("Digite o numero de algum no para verificar o nivel do pai: ");
        scanf("%d", &n);
        aux.n=n;
        printf("Nivel do pai: %d\n", pai(&(*raiz), aux));
        break;
    case 5:
        printf("Tamanho: %d\n", altura(&(*raiz)));
        break;
    default:
        printf("Opcao invalida\n");
        break;
    };
    printf("Se deseja repetir, digite 1: ");
    scanf("%d", &repetir);
    }
    return 0;
}


void cria(no **raiz){
    *raiz = NULL;
}

int vazia(no *raiz){
    if(raiz==NULL){
        return 1;
    }
    return 0;
}

void insere(no **raiz, int v){
    if(*raiz == NULL){
        *raiz = (no*)malloc(sizeof(no));
        (*raiz)->dir=NULL;
        (*raiz)->esq=NULL;
        (*raiz)->n=v;
    }
    else{
        if(v>(*raiz)->n){
            insere(&((*raiz)->dir), v);
        }
        else{
            insere(&((*raiz)->esq), v);
        }
    }
}

int nivel(no **raiz, int v){
    int cont;
    no *atual;
    atual=raiz;
    cont=1;
    while(atual){
        if(atual->n==v){
            return cont;
        }
        if(v>atual->n){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
        cont ++;
    }
    if(atual==NULL){
        printf("Nao encontrado!\n");
    }
    return 0;
}

int pai(no **raiz, no b){
    int cont=1;
    no *atual;
    atual = raiz;
    while(atual->dir!=NULL||atual->esq!=NULL){
        if(b.n==atual->dir->n||b.n==atual->esq->n){
            return cont;
        }
        if(b.n>(*atual).n){
            atual=atual->dir;
        }
        else{
            atual=atual->esq;
        }
        cont++;
    }
    return 0;
}

/*int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}//maior*/



int altura(no *pRaiz){
   if
        ((pRaiz == NULL) || (pRaiz->esq == NULL && pRaiz->dir == NULL)){
       return 0;}
   else{
        if(altura(pRaiz->esq)>altura(pRaiz->dir)){
            return 2+ altura(pRaiz->esq);
        }
        else{
            return 2+ altura(pRaiz->dir);
        }
       //return 1 + maior(altura(pRaiz->esq), altura(pRaiz->dir)+1);
   }
}
