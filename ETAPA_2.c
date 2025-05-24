//Gabriel Henriques Spíndola

#include <stdio.h>
#include <stdlib.h>

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

        //imprime a matriz
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                printf("%3d", mat[i][j]);
            printf("\n");
        }

        fclose(arq);
    }

    return 0;
}