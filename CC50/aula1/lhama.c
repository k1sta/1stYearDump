#include <stdio.h>
#include <math.h>

int main(){
    //data dictionary
    int pop_init, pop_end, years = 0;

    //input gathering for pop_init and pop_end
    do{
        printf("Start population: ");
        scanf("%d", &pop_init);
    } while (pop_init < 9);
    do{
    printf("End population: ");
    scanf("%d", &pop_end);
    } while(pop_end <= pop_init);

    //years calculation
    while (pop_end > pop_init){
        pop_init += (pop_init / 3) - (pop_init / 4);
        years++;
    }

    //output
    printf("Years: %d\n", years);

    //return
    return 0;
}