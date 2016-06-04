#include <stdio.h>

#include "fila.h"

int main() {
    int x, i;
    TFila *f = CriarFila();
    f->enfileirar(f, 5);
    f->enfileirar(f, 8);
    f->enfileirar(f, 9);
    f->enfileirar(f, 54);
    f->enfileirar(f, 90);

    f->desenfileirar(f);
    f->desenfileirar(f);
    f->desenfileirar(f);

    f->enfileirar(f, 20);

    f->desenfileirar(f);

    f->enfileirar(f, 5);
    f->enfileirar(f, 8);
    f->enfileirar(f, 9);

    printf("\nBIP BIP BIP\n");

    f->enfileirar(f, 5);
    f->enfileirar(f, 8);
    f->enfileirar(f, 9);

    f->desenfileirar(f);
    f->desenfileirar(f);
    f->desenfileirar(f);
    /*for (i = 1; !f->vazia(f); i++ ) {
        printf("Elemento %d: %d\n", i, f->desenfileirar(f));
    }*/

    return 0;
}
