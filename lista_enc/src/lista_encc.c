#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

#define DEBUG

struct listas_enc {
    no_t *cabeca;   /*!< Refer�ncia da cabe�a da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Refer�ncia da cauda da lista encadeada: �ltimo elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (refer�ncia) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obt�m a refer�ncia do in�cio (cabe�a) da lista encadeada.
  * @param	lista: lista que se deseja obter o in�cio.
  *
  * @retval no_t *: n� inicial (cabe�a) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}
/* 			adiciona um n� de lista inicio
			 elemento: n� que ser� adicionado na cabe�a
*/

void add_cabeca(lista_enc_t *lista, no_t* elemento)
{
	 if (lista == NULL || elemento == NULL){
	        fprintf(stderr,"add_cabeca: ponteiros invalidos");
	        exit(EXIT_FAILURE);
	    }
	 #ifdef DEBUG
	 printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
  	 #endif // DEBUG
	 if (lista->tamanho == 0)
	    {
	         #ifdef DEBUG
	         printf("add_cabeca: add primeiro elemento: %p\n", elemento);
	         #endif // DEBUG

	         lista->cauda = elemento;
	         lista->cabeca = elemento;
	         lista->tamanho++;

	         desligar_no(elemento);
	    }
	 else {

	        // Liga cabeca da lista com novo elemento
	        ligar_nos(elemento, lista->cabeca);

	        lista->cabeca = elemento;
	        lista->tamanho++;
	   }

}

void remove_cabeca(lista_enc_t *lista, no_t* elemento)
{
	elemento = obter_proximo(lista->cabeca);
	lista->cabeca = elemento;

}

int tamanho_lista(lista_enc_t *lista)
{
	int i = 0;
	if(lista == NULL){
		return 0;
	}
	no_t *no = obter_cabeca(lista);

	while(no != NULL){
		no = obter_proximo(no);
		i ++;
	}
	return i;
}
/**
  * @brief  Adiciona um n� de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: n� que ser� adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}
