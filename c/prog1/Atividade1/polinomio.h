typedef struct {
float c3, c2, c1, c0;
} polinomio;

//Exemplo de representação de polinômio pela estrutura acima (de coeficientes):
// Para c3 = 1, c2 = 5, c1 = 4 e c0 = -3, o polinômio correspondente será:
// x3 + 5x2 + 4x - 3

typedef struct { //Raízes de um polinômio de grau 2.
    double x1, x2;
} solucao;

polinomio somarPoli(polinomio p1, polinomio p2); //soma que soma que soma os coeficientes

polinomio derivadaPoli(polinomio p); //Ex.: derivada(x3 + 5x2 + 4x - 3) = 3x2 + 10x + 4

solucao raizesPoli(polinomio p); //Aceitar apenas polinômios de grau 2!

float valorPoli(polinomio p, int x); //Ex.: para x = 1, temos que x3 + 5x2 + 4x - 3 = 7