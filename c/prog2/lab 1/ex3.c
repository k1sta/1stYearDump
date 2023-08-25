#include <stdio.h>
#include <string.h>

int vogais1(char *v);
int vogais2(char v[]);

int testeVogal(char letra);

int main (){
    char v[] = {"Aqui existem 9 vogais"};

    for (int i = 0; i < 1000; i++){
        if (v[i] == '\0') break;
        printf("%c", v[i]);
    }
    printf("\n");

    printf("%d vogais, de acordo com a 1\n", vogais1(&v[0]));
    printf("%d vogais, de acordo com a 2\n", vogais2(v));

    return 0;
}

int vogais1(char *v){
    int temp = 0, i = 0;
    while (*(v + i) != '\0'){
        if (testeVogal(*(v + i))) temp++;
        i++;
    }

    return temp;
}

int vogais2(char v[]){
    int temp = 0, i = 0;
    while (v[i] != '\0'){
        if (testeVogal(v[i])) temp++;
        i++;
    }

    return temp;
}

int testeVogal(char letra){
    return (letra == 65 || letra == 69 || letra == 73 || letra == 79 || letra == 85 || letra == 97 ||letra == 101 || letra == 105 ||letra == 111 || letra == 117) ? 1 : 0;
}