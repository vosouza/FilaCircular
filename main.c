
//bibliotecas
#include <stdio.h>
#include "Booleano.h"

#define max_fila 8
#define sentinela -1
#define fantasma -2

typedef struct{
    int inicio;
    int fim;
    int item[max_fila];
}FilaCircular;

void criarFilaVazia(FilaCircular *);
int acessarInicio(FilaCircular *);
bool verificarFilaVazia(FilaCircular *);
bool verificarFilaCheia(FilaCircular *);
void push(FilaCircular *, int );
void pop(FilaCircular *);
void esvaziarFila(FilaCircular *);


void main(){
    FilaCircular fila;
    criarFilaVazia(&fila);
    push(&fila,1);
    push(&fila,2);
    push(&fila,3);
    push(&fila,4);
    push(&fila,5);
    push(&fila,6);
    push(&fila,7);
    push(&fila,8);
    push(&fila,9);
    for(int i =0;i<max_fila -1;i++){
        printf("%d\n\n", fila.item[i]);
    }

}

void criarFilaVazia(FilaCircular *f){
    f->fim =sentinela;
    f->inicio=sentinela;
}

int acessarInicio(FilaCircular *f){
    int item = fantasma;

    if(f->inicio != sentinela){
        item =  f->item[f->inicio];
    }
    return item;
}

bool verificarFilaVazia(FilaCircular *f){
    bool ok = FALSE;
    if(f->fim == sentinela)ok=TRUE;
    return ok;
}

bool verificarFilaCheia(FilaCircular *f){
    bool ok = FALSE;
    if(f->fim != sentinela)ok=TRUE;
    return ok;
}

void push(FilaCircular *f, int item){
    int fim  = f->fim;
    if((fim++) != f->inicio){
        fim = (fim)%max_fila;
        f->item[fim] = item;
        f->fim = fim;
    }

    if(f->fim == sentinela && f->inicio==sentinela){
        f->inicio = fim;
    }
}

void pop(FilaCircular *f){
    if(f->fim != sentinela ){
        if(f->fim == f->inicio){
            f->fim = sentinela;
            f->inicio = sentinela;
        }else{
            f->inicio -= 1;
        }
    }
}


void esvaziarFila(FilaCircular *f){
    f->fim = sentinela;
    f->inicio = sentinela;
}
