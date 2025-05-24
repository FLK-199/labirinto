//Gabriel Henriques Spíndola

#include <stdio.h>
#include <stdlib.h>

#include ".\estruturas\fila_e.h"

void anotacao(int N, int mat[][N]);

int main()
{   
    char c;
    int N = 0;
    FILE *arq = fopen("labirinto.txt", "r");

    if(arq != NULL)
    {
        //Conta a quantidade de '#' da primeira linha (tamanho N da martiz)
        while(1)
        {
           fscanf(arq, "%c", &c);

           if(c == '#')
           N++;
           else break;
        }

        rewind(arq);  

        //Armazena na matriz, -1 para parede e 0 para espaços livres
        int mat[N][N], i = 0, j = 0; 

        while(fscanf(arq, "%c", &c) != EOF)
        {
            if(c != '\n' && c == '#')
            {
                mat[i][j] = -1;
                j++;
            }  
            else if(c != '\n' && c == '.')
            {
                mat[i][j] = 0;
                j++;
            }
            else 
            {
                j = 0;
                i++;
            }
        }

        //Figura2-a
        char a[N][N];
        printf(" Figura 2-a\n");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
            {
                if(mat[i][j] == -1)
                {
                    a[i][j] = '#';
                }  
                else if(mat[i][j] == 0)
                {
                    a[i][j] = ' ';
                }
                printf("%2c ", a[i][j]);
            }
            printf("\n");
        }

        FILE *a_2 = fopen("F2a.txt", "w");

        if(a_2 != NULL)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    fprintf(a_2, "%c ", a[i][j]);
                }

                fprintf(a_2, "\n");
            }

            fclose(a_2);
        }

        printf("\n");


        //Figura 2-b
        printf(" Figura 2-b\n");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                printf("%3d", mat[i][j]);
            printf("\n");
        }
        
        FILE *b_2 = fopen("F2b.txt", "w");

        if(b_2 != NULL)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    fprintf(b_2, "%2d ", mat[i][j]);
                }

                fprintf(b_2, "\n");
            }

            fclose(b_2);
        }

        printf("\n");

        //Figura 2-c
        printf(" Figura 2-c\n");
        anotacao(N, mat);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                printf("%3d", mat[i][j]);
            printf("\n");
        }

        FILE *c_2 = fopen("F2c.txt", "w");

        if(c_2 != NULL)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    fprintf(c_2, "%2d ", mat[i][j]);
                }

                fprintf(c_2, "\n");
            }

            fclose(c_2);
        }

        fclose(arq);
    }

    return 0;
}

void anotacao(int N, int mat[][N])
{
    fila *f = fila_inicializar();
    ponto2D p;

    p.x = 1;
    p.y = 1;
    mat[p.x][p.y] = 1;

    fila_inserir(f,p);

    while(!fila_vazia(f))
    {
        p = fila_frente(f);

        fila_remover(f);

        if(mat[p.x+1][p.y] == 0)
        {
            ponto2D t1;
            t1.x = p.x+1;
            t1.y = p.y;
            fila_inserir(f,t1);
            mat[t1.x][t1.y] = mat[p.x][p.y] + 1;
        }

        if(mat[p.x-1][p.y] == 0)
        {
            ponto2D t2;
            t2.x = p.x-1;
            t2.y = p.y;
            fila_inserir(f,t2);
            mat[t2.x][t2.y] = mat[p.x][p.y] + 1;
        }

        if(mat[p.x][p.y+1] == 0)
        {
            ponto2D t3;
            t3.x = p.x;
            t3.y = p.y+1;
            fila_inserir(f,t3);
            mat[t3.x][t3.y] = mat[p.x][p.y] + 1;
        }

        if(mat[p.x][p.y-1] == 0)
        {
            ponto2D t4;
            t4.x = p.x;
            t4.y = p.y-1;
            fila_inserir(f,t4);
            mat[t4.x][t4.y] = mat[p.x][p.y] + 1;
        }
    }
}