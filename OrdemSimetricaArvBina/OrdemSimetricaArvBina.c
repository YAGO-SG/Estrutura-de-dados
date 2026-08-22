#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no * esq;
    struct no * dir;
}Tnoa;

typedef struct lista {
    Tnoa * no;
    struct lista * prox
} Tlista;

Tlista * push(Tnoa * no, Tlista * lista) {
    Tlista * novo = (Tlista*) malloc(sizeof(Tlista));
    novo->no = no;
    novo->prox = lista;

    return novo;
}

Tlista * pop(Tlista * lista) {
    Tlista * aux = lista->prox;
    free(lista);

    return aux;
}

void implementaNo(Tnoa * a, int x, int y) {
    Tnoa * novo1 = (Tnoa*) malloc(sizeof(Tnoa));
    Tnoa * novo2 = (Tnoa*) malloc(sizeof(Tnoa));
    novo1->info = x;
    novo1->esq = NULL;
    novo1->dir = NULL;
    novo2->info = y;
    novo2->esq = NULL;
    novo2->dir = NULL;
    a->esq = novo1;
    a->dir = novo2;
}

void imprimeNo(Tnoa * arv, int a) {

    if(arv != NULL) {
        char espaço[a + 1];
        for(int i = 0; i < a; i++) {
            espaço[i] = '-';
        }

        espaço[a] = '\0';

        printf("%s %d\n", espaço, arv->info);

        imprimeNo(arv->esq, a + 2);
        imprimeNo(arv->dir, a + 2);
    }
}

void OrdemSimetrica(Tnoa * arvore) {

}


int main() {
    Tnoa * head = (Tnoa*) malloc(sizeof(Tnoa));
    head->info = 5;

    implementaNo(head, 1, 3);
    implementaNo(head->esq, 34, 54);
    implementaNo(head->dir, 23, 85);

    imprimeNo(head, 0);
    espelho(head);
    imprimeNo(head, 0);

    return 0;
}