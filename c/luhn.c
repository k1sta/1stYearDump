#include <stdio.h>
#include <math.h>

int checksum(int digit[]){

}

int main(){
    long int card_number;
    int card_flag;

    printf("Type your credit card number: ");
    scanf("%li", &card_number);

    int n = floor(log10(abs(card_number)));
    int digit[n];

    for(int i = n -1; i > 0; i--){
        digit[i] = card_number % 10;
        card_number = floor(card_number / 10);
    }

    if (digit[0] = 4){
        if (n = 13 || n = 16){
            card_flag = 1;

        } else {

        }

    } else if (digit[0] = 5 ){

    } else if (digit[0] = 3){

    } else{
        printf("INVALID");
    }

    return 0;
}