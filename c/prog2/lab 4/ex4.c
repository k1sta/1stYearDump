#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int comparison(char *word1, char *word2);

int main(int argc, char **argv){
    FILE *fpIn;
    char word[50];
    int sum = 0;

    fpIn = fopen (argv[1], "r");
    if (fpIn == NULL) return -1;

    while(!feof(fpIn)){
        fscanf(fpIn, "%s ", word);
        sum += comparison(word, argv[2]);
    }

    printf("%d\n", sum);
    
    fclose(fpIn);
    return 0;
}

int comparison(char *word1, char *word2){
    int n, n1 = strlen(word1), n2 = strlen(word2);
    n = (n1 > n2) ? n1 : n2;
    for(int i = 0; i < n; i++){
        if(toupper(word1[i]) != toupper(word2[i])) return 0;
    }
    return 1;
}