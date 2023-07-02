#include <stdio.h>

int main(){
  int size_vec, orig[1000], ord[1000];

  puts("Insert the number of the array: ");
  scanf("%d", &size_vec);

  printf("Insert %d values: \n", size_vec);
  for(int i = 0; i < size_vec; i++){
    scanf("%d", &orig[i]);
    ord[i] = orig[i];
  }

  do{
    int aux, counter = 0;
    for(int i = 1; i < size_vec; i++){
      if (ord[i-1] > ord[i]){
        aux = ord[i];
        ord[i] = ord[i-1];
        ord[i-1] = aux;
      } else counter++;
      
    }
  } while(counter != size_vec-1);
  
  for(int i = 0; i < size_vec; i++){
    printf("%d", ord[i]);
  }
  
  printf("\n");

  return 0;
    
    
}