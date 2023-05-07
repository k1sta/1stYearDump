/*
A ideia desse codigo eh calcular a legibilidade de um código baseado no indice Coleman-Liau.

Deve-se encontrar a media de letras por 100 palavras, a media de frases por 100 sentenças e inseri-las
na formula índice = 0,0588 * L - 0,296 * S - 15,8. O resultado desse indice e o nivel de leitura desse
texto.

Portanto, o pseudocodigo seria algo mais ou menos assim

1. Input do texto
2. Calcular a media de letras por 100 palavras
    2.1 Pode-se realizar esta tarefa através de uma regra de tres. letras_input * 100 = palavras_input * letras_media
3. Calcular a media de frases por 100 palavras
    3.1 Para isso, deve-se criar uma iteração onde a cada '.' '!', '?' é considerado 1 frase e realizar
    o mesmo calculo do 2.1
4. Realizar o calculo atraves da formula do indice Coleman-Liau
5. Retornar indice
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    //data dictionary
    char s[1000];
    int indice, words_input = 1, letters_input = 0, phrases_input = 0;
    float letters_media, phrases_media;

    //input gathering
    printf("Text: ");
    fgets(s, 1000, stdin);
    int n = strlen(s);
    
    //number of letters, words and phrases in the input
    for (int i = 0; i < n; i++){
        if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123 )){
            letters_input++;
        }

        if (s[i] == ' '){
            words_input++;
        }

        if (s[i] == 33 || s[i] == 63 || s[i] == 46){
            phrases_input++;
        }

    }

    //media calculation
    letters_media = (letters_input * 100.00) / words_input;
    phrases_media = (phrases_input * 100.0) / words_input;

    //Coleman-Liau
    indice = 0.0588 * letters_media - 0.296 * phrases_media - 15.8;

    //output
    if (indice < 1) {
        printf("Before Grade 1.\n");
    } else if (indice < 17){
        printf("Grade %d\n", indice);
    } else {
        printf("Grade 16+");
    }

    //function return
    return 0;
}
