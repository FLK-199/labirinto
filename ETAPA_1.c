//Gabriel Henriques Spíndola

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N, P;
    
    scanf("%d %d", &N, &P);

    //verifica se os parâmetros N e P tem entrada válida
    if((P > 80 || P < 10) && (N > 100 || N < 7))
    {
        printf("entrada invalida\n");
        return 0;
    }
    
    char mat[N][N];

    //inicia o labirinto com '.' em todos os sesu índices
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            mat[i][j] = '.';
        }
    }

    //constrói as bordas do labirinto
    for(int i = 0; i < N; i++)
    {
        mat[0][i] = '#';
        mat[i][0] = '#';
        mat[i][N-1] = '#';
        mat[N-1][i] = '#';
    }

    //gera as paredes no interior do labirinto
    srand(time(NULL));

    for(int i = 1; i < N-1; i++)
    {
        for(int j = 1; j < N-1; j++)
        {
            //if(j%2 == 0)
            if((rand()%100+1) <= P)
            mat[i][j] = '#';
        }
    }

    //cria o arquivo "labirinto.txt"
    FILE *lab = fopen("labirinto.txt", "w");

    if(lab != NULL)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                fprintf(lab, "%c", mat[i][j]);
            }

            fprintf(lab, "\n");
        }

        fclose(lab);
    }

    return 0;
}