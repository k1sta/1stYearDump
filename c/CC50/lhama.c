#include <stdio.h>
#include <math.h>

int main(){
    int pop_init, pop_end, years = 0;
    do{
        printf("Start population: ");
        scanf("%d", &pop_init);
    } while (pop_init < 9);
    do{
    printf("End population: ");
    scanf("%d", &pop_end);
    } while(pop_end <= pop_init);

    while (pop_end > pop_init){
        pop_init += (pop_init / 3) - (pop_init / 4);
        years++;
    }

    printf("Years: %d\n", years);
    return 0;
}