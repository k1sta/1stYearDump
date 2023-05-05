#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define VISACODE 0
#define AMEXCODE 1
#define MASTERCARDCODE 2
#define ERRORCODE 3

//prototypes
bool checksum(int digit[], int n);
int card_flag(int digit[]);

int main(){
    //data dictionary
    long long card_number_var;
    int n = 0, flag_code;

    //input gathering
    printf("Type your credit card number: ");
    scanf("%lld", &card_number_var);

    //seting up const
    const long long card_number_const = card_number_var;

    //digit collect
    while (card_number_var != 0){
        card_number_var = floor(card_number_var / 10);
        n++;
    } card_number_var = card_number_const;

    int digit[n];

    for(int i = n - 1; i >= 0; i--){
        digit[i] = card_number_var % 10;
        card_number_var = floor(card_number_var / 10);
    }   card_number_var = card_number_const;


    //difining the flag code
    flag_code = card_flag(digit);
    
    //flag code check
    switch (flag_code)
    {
    case VISACODE:
        //digits check
        if (n == 13 || n == 16){
            if (checksum(digit, n) == true){
                printf("VISA\n");
            } else {
                printf("INVALID\n");
                return 3;
            }
        } else {
            printf("INVALID\n");
            return 2;
        }
        break;
    
    case AMEXCODE:
        //digits check
        if (n == 15){
            if (checksum(digit, n) == true){
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
                return 3;
            }
        } else {
            printf("INVALID\n");
            return 2;
        }
        break;

    case MASTERCARDCODE:
        //digits check
        if (n == 16){
            if (checksum(digit, n) == true){
                printf("MASTERCARD\n");
            } else {
                printf("INVALID\n");
                return 3;
            }
        } else {
            printf("INVALID\n");
            return 2;
        }
        break;
            
    default:
        //flag code is not recognized
        printf("INVALID\n");
        return 1;
    }


    return 0;
}

/*this function checks up the initial digits of an array that represents
a card number and returns the flag*/
int card_flag(int digit[]){
    if (digit[0] == 4){ // visa
        return VISACODE;
    } else if (digit[0] == 3 && (digit[1]==4 || digit[1]==7)){ // amex
        return AMEXCODE;
    } else if (digit[0] == 5 && (digit[1] > 0 || digit[1] <= 5)){ // master card
        return MASTERCARDCODE;
    } else {
        return ERRORCODE;
    }
}

/*this function validates a credit card number using the luhns algorithm.
this fuction requires an array that represents a card number and the 
number of digits that the card number  has*/
bool checksum(int digit[], int n){
    int sum = 0, temp;

    for(int j = n - 2; j >= 0; j -= 2){
        if (digit[j] * 2 >= 10){
            temp = digit[j] * 2;
            while (temp != 0){
                sum += temp % 10;
                temp = floor(temp / 10);
            }
        } else{
            sum += digit[j] * 2;
        }
    }

    for(int k = n - 1; k >= 0; k -= 2){
        sum += digit[k];
    }

    if (sum % 10 == 0){
        return true;
    } else {
        return false;
    }
}