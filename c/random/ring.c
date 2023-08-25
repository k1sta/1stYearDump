/*
Description: this program has the function of find the area of an ring
Input: the outer and the inner circle radius
Output: the area of the ring
*/

#include <stdio.h>

int main() {
    //data dictionary
    float r1, r2; //unsanitized input
    float rB, rS; //sanitized input
    float area; //output data

    //inputs gathering
    printf("Digite os raios separados por um espaço: \n");
    scanf("%f %f", &r1, &r2); 

    //checks whos bigger
    if (r1 > r2) {
        rB = r1;
        rS = r2;
    } else {
        rS = r1;
        rB = r1;
    }

    //calculates the area
    area = ((3.14 * rB * rB) - (3.14 * rS * rS));

    //print it
    printf("A área do anel é igual a %f \n", area);
}