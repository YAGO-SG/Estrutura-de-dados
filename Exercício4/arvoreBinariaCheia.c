#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no * esq;
    struct no * dir;
}Tnoa;

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

int verificaNo(Tnoa * a) {
    int no = calculaNo(a);
    int res = 1;
    int pot = 1;
    while(true) {
        if(no == res) {
            return 1;
        } else if (res > no) {
            return 0;
        } else {
            res += powi(2, pot);
            pot += 1;
        }
    }
}


int main() {
    Tnoa * head = (Tnoa*) malloc(sizeof(Tnoa));
    head->info = 5;

    implementaNo(head, 1, 3);
    implementaNo(head->esq, 34, 54);
    implementaNo(head->dir, 23, 85);
    implementaNo(head->esq->esq, 86, 95);

    int no = 0;
    no = calculaNo(head);

    imprimeNo(head, 0);
    printf(" %d", no);

    int verifica = verificaNo(head);
    if(verifica == 1) {
        printf("\n A arvore binaria apresentada é do tipo cheia");
    } else if(verifica == 0) {
        printf("\n A arvore binarioa não é do tipo cheia");
    }

    return 0;
}