#include <stdio.h>
typedef struct date {int day, month, year;} tDate;



int main(){
    tDate data, copia;
    int temp;
    
    do{
        puts("type the day, month and year in this order separated with an space: ");
        scanf("%d %d %d", &data.day, &data.month, &data.year);
        printf("The date is %d/%d/%d?\n", data.day, data.month, data.year);
        scanf("%d", &temp);
        if (temp == 1 && data.year > 1900){
            if (data.month > 0 && data.month <= 7){
                if (data.month == 2){
                    if (data.year % 4 == 0){
                        if (data.day > 0 && data.day <= 29) break;
                    } else {
                        if (data.day > 0 && data.day <= 28) break;
                    }
                } else if (data.month % 2 == 0) {
                    if (data.day > 0 && data.day <= 30) break;
                } else {
                    if (data.day > 0 && data.day <= 31) break;
                }
            } else if (data.month <= 12){
                if (data.month % 2 == 0) {
                    if (data.day > 0 && data.day <= 31) break;
                } else {
                    if (data.day > 0 && data.day <= 30) break;
                }
            }
        }
        puts("Invalid date");
    } while (1);

    printf("The inserted date is: %d/%d/%d\n", data.day, data.month, data.year);

    return 0;
}