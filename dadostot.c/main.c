#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <string.h>

int main()
{
    int i;
    int n_linhas = 0;

    //dado_t *dados = ler_dados_csv("camera_temp.csv", &n_linhas);
    dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    /* Imprima os dados:*/
    for (i=0; i<n_linhas; i++)
    {
        //printf( "...", dados[i]->amostra, ... );
        printf("%d,%.1f,%s\n", imprime_amostra(dados[i]), imprime_temperatura(dados[i]), imprime_tempo(dados[i]));
    }

    // liberar_dados();
    liberar_dados(dados, n_linhas);

    //fclose(dados);
    return 0;
}
