typedef struct fila TFila;

TFila* criarFila();

void imprimirFila(TFila *f);

typedef short (*TEnfileirar)(TFila*, int);
typedef int (*TDesenfileirar)(TFila*);
typedef short (*TVazia)(TFila*);

struct fila {
	void *dado;
	TEnfileirar enfileirar;
	TDesenfileirar desenfileirar;
	TVazia vazia;
};


