#include <stdio.h>
#include <stdlib.h>

 // Implementacao de FILA // ref: Notas de aula
 // http://www2.dcc.ufmg.br/livros/algoritmos/cap3/slides/c/completo1/cap3.pdf secao 3.3.2
 struct Node {
	int item;
	struct Node *next;
 };

 struct Fila {
	struct Node *head;
	struct Node *tail;
 };


 struct Fila* criaFilaVazia() {
    struct Fila* Fila = (struct Fila *) malloc(sizeof(struct Fila));
    Fila->head = Fila->tail = NULL;
	return Fila;
 }

 int Vazia(struct Fila* Fila) {
	 return (Fila->head==NULL);
 }

 void enfileira(int item, struct Fila* Fila) {
     struct Node * celula = (struct Node *) malloc(sizeof(struct Node));
	 celula->item = item;
	 celula->next = NULL;

	 if (Fila->tail) {
        Fila->tail->next = celula;
        Fila->tail = Fila->tail->next;
	 }
	 else {
        Fila->head = celula;
        Fila->tail = celula;
	 }

 }
 int desenfileira(struct Fila* Fila) {
     //printf("desenfileirando\n");
     int item;

	 if (Vazia(Fila)) {
		 printf("Erro. Fila ja esta vazia.\n");
		 return -1;
	 }

	 struct Node* node = (struct Node*) malloc(sizeof(struct Node));

	 node = Fila->head;
     item = node->item;
	 Fila->head = node->next;

     if (Fila->head == NULL)
        Fila->tail = NULL;
	 free(node);
     //printf("saindo do desenfileira\n");
	 return item;
 }
