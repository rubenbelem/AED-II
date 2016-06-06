#include <stdio.h>
#include <windows.h>
#include "fila.h"

int main() {
    TFila *f = criarFila();
    f->enfileirar(f, 5);
    f->enfileirar(f, 8);
    f->enfileirar(f, 9);
    f->enfileirar(f, 54);
    f->enfileirar(f, 90);

    f->desenfileirar(f);
    f->desenfileirar(f);
    f->desenfileirar(f);

    f->enfileirar(f, 20);
    f->enfileirar(f, 25);

    printf("\nBIP BIP BIP\n\n");

    f->enfileirar(f, 5);
    f->enfileirar(f, 8);
    f->enfileirar(f, 9);
    f->desenfileirar(f);
    f->desenfileirar(f);

    f->enfileirar(f, 34);
    f->enfileirar(f, 35);
    f->enfileirar(f, 36);
    f->enfileirar(f, 37);
    f->enfileirar(f, 38);
    f->enfileirar(f, 40);

    printf("\n\nTERMINI!");
    system("pause");
    return 0;
}
