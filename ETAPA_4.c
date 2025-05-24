//Gabriel Henriques Spíndola

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include ".\estruturas\fila_e.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

void anotacao(int N, int mat[][N]);
void extracao(int N, int mat[][N], pilha *p);

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

        //Figura 3-b
        ponto2D b3;
        pilha *z = pilha_inicializar();
        extracao(N, mat, z);

        printf("\n\n Figura 3-b\n");
        while(!pilha_vazia(z))
        {
            b3 = pilha_topo(z);
            a[b3.x][b3.y] = 'x';
            pilha_remover(z);
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
            {
                if((i == 1 && j == 1) || (i == N - 2 && j == N - 2))
                printf(GRN " %c " RESET, a[i][j]);
                else if(a[i][j] == 'x')
                printf(RED " %c " RESET, a[i][j]);
                else
                printf(" %c ", a[i][j]);
            }
            printf("\n");
        }

        FILE *b_3 = fopen("F3b.txt", "w");
        if(b_3 != NULL)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    fprintf(b_3, "%c ", a[i][j]);
                }

                fprintf(b_3, "\n");
            }

            fclose(b_3);
        }

        fclose(arq);
        pilha_finalizar(z);
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

    fila_finalizar(f);
}

void extracao(int N, int mat[][N], pilha *p)
{
    ponto2D pon;

    pon.x = N-2;
    pon.y = N-2;
    pilha_inserir(p, pon);

    printf("\n menor caminho: ");

    while(pon.x != 1 || pon.y != 1)
    {
        printf("(%d,%d) ", pon.x,pon.y);

        if(mat[pon.x+1][pon.y] == mat[pon.x][pon.y] - 1)
        {
            ponto2D t1;
            t1.x = pon.x+1;
            t1.y = pon.y;
            pilha_inserir(p, t1);
        }

        else if(mat[pon.x-1][pon.y] == mat[pon.x][pon.y] - 1)
        {
            ponto2D t2;
            t2.x = pon.x-1;
            t2.y = pon.y;
            pilha_inserir(p, t2);
        }

        else if(mat[pon.x][pon.y+1] == mat[pon.x][pon.y] - 1)
        {
            ponto2D t3;
            t3.x = pon.x;
            t3.y = pon.y+1;
            pilha_inserir(p, t3);
        }

        else if(mat[pon.x][pon.y-1] == mat[pon.x][pon.y] - 1)
        {
            ponto2D t4;
            t4.x = pon.x;
            t4.y = pon.y-1;
            pilha_inserir(p, t4);
        }

        else 
        {
            printf("\n nao ha caminho\n\n");
            return;
        }

        pon = pilha_topo(p);
    }
}
