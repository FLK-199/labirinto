// Arquivo cabeçalho

// INTERFACE DO TAD

// Dados
typedef struct ponto ponto2D; // criar variáveis

struct ponto { // dados
    int x, y;
};

// Operações (declaração das operações => protótipos das funções)

/*
Calcula a distância entre o ponto p e a origem
Entrada: ponto p
Saída: a distância calculada
*/
float distancia(ponto2D p);

/*
Exibe o ponto p no formato de um par ordenado
Entrada: ponto p
Saída: Não tem
*/
void exibir_ponto(ponto2D p);

/*
Move o ponto p com deslocamento de dx no eixo das abscissas e
dy no eixo das ordenadas
Entrada: referência para o p e os deslocamentos dx e dy
Saída: Não tem
*/
void mover(ponto2D *p, float dx, float dy);
