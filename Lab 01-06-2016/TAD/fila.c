/*
AED-II Atividade de Lab.
June 1, 2016
Leave a Comment
Car@s
Para a aula de hoje, as atividades são as seguintes:
1) Implementação do TAD Fila considerando encapsulamento de dados e as operações;
2) Sua implementação é eficiente? A eficiência aqui está relacionada ao custo de inserir e remover elementos da fila.
3) Se a sua resposta for Não, como você pode melhorar o seu código?
O código enviado, na postagem anterior, deve servir de base para você construir o TAD. Observe que naquele código um vetor foi utilizado para armazenar os elementos da fila.
–Cesar Melo–Instituto de Computação/UFAM
–(92) 9966-4442 (móvel)
–(92) 3305-1181 Ramal 2066
Posted in Ensino
AED-II O Código, e as filas
May 31, 2016
Leave a Comment
Prezad@s
segue um protótipo dos códigos relacionados a manipulação de uma fila, conforme escrito no arquivo (fila.c).*/
#include "fila.h"
#include <stdlib.h>
#define NaN 0/0.
#define TAM 5

typedef struct
{
    int primeiro;
    int ultimo;
    int contagem;
    int tamanho;
    int *fila;
} TDado;
/** Remove o primeiro elemento da fila. Para a fila passada, o primeiro elemento será removido se ele existir.
* No caso da fila vazia, a operação não é realizada e um NaN é retornado.
*
* Pré-cond: Fila criada.
*
* Pós-cond: Elemento removido, se fila não estiver vazia.
*/
static int Desenfileirar(TFila *f)
{
    int elemento;
    TDado *d = (TDado*) f->dado;
    if (d->primeiro == -1)
    {
        elemento = NaN;
    }
    else
    {
        elemento = d->fila[d->primeiro];
        d->fila[d->primeiro] = 0;

        d->contagem--;

        if (d->primeiro == d->ultimo)
        {
            d->primeiro = d->ultimo = -1;
        }
        else {
            if (d->primeiro + 1 < TAM) {
                d->primeiro++;
            }
            else {
                d->primeiro = 0;
            }
        }
    }

    return elemento;
}
/** Insere um novo elemento na fila. Para uma fila criada
* a função irá inserir o elemento passado
* considerando a ocupação da fila. o retorno indica se a
* operação foi realizada com sucesso.
*
* Pré-cond: fila criada, e elemento a ser inserido.
*
* Pós-Cond: elemento inserido na fila, se houver espaço.
*/
static short Enfileirar(TFila *f, int elemento)
{
    short status = 1; // verdade (vai dar tudo certo)
    TDado *d = f->dado;
    if (d->primeiro == -1)
    {
        d->primeiro=d->ultimo=0;
        d->fila[d->primeiro] = elemento;
    }
    else if (d->contagem < d->tamanho)
    {
        d->ultimo = (d->ultimo + 1) % d->tamanho;
        d->fila[d->ultimo] = elemento;
    }
    else status = 0;//falso (deu errado)

    d->contagem += (int) status;
    return status;
}
/**Verifica a ocupação da fila. Para uma fila criada, verifica se ela tem UM elemento, pelo menos. Caso haja elementos o status retornado é de que a fila NÃO está vazia, caso contrário tem-se a indicação de fila vazia.
*
*Pré-cond: Fila criada.
*
*Pós-cond: Fila inalterada.
*/
static short Vazia(TFila *f)
{
    TDado *d = f->dado;
    if (d->primeiro == -1)
        return 1;
    return 0;
}

/** Cria a fila, se ela já não houver sido criada.
*
* Pré-cond: Fila não existe.
*
* Pós-cond: Fila criada.
*/

void imprimirFila(TFila *f) {
    int i;
    TDado *d = f->dado;
    for (i = 0; i < TAM; i++) {
        printf("%d ", d->fila[i]);
    }
    printf("\n");
}

void expandirFila(TFila *f) {
	TDado *d = (TDado*) f->dado;
	int *v = (int*) malloc(sizeof(int) * (d->tamanho + 10));
	int i, aux;

	if (d->primeiro < d->ultimo) {
		for (i = d->primeiro; i <= d->ultimo; i++) {
			v[i - d->primeiro] = d->fila[i];
		}

		d->ultimo = d->ultimo - d->primeiro;
		d->primeiro = 0;
	}
	else {
		for (i = d->primeiro; i < d->tamanho; i++) {
			v[i - d->primeiro] = d->fila[i];
		}

		aux = d->tamanho - d->primeiro;

		for (i = 0; i <= d->ultimo; i++) {
			v[aux + i] = d->fila[i];
		}

		d->primeiro = 0;
		d->ultimo = (d->tamanho - d->primeiro) + d->ultimo + 1;
	}

	free(d->fila);
	d->tamanho += 10;
	d->fila = v;
}

TFila* criarFila()
{
	TFila *f = (TFila*) malloc(sizeof(TFila));
	TDado *d = (TDado*) malloc(sizeof(TDado));

	d->primeiro = -1;
	d->ultimo = -1;
	d->contagem = 0;
	d->tamanho = TAM;
	d->fila = (int*) malloc(sizeof(int) * d->tamanho);

	f->desenfileirar = Desenfileirar;
	f->enfileirar = Enfileirar;
	f->vazia = Vazia;
	f->dado = d;

	return f;
}
