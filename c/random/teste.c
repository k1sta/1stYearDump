#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main(){


double x, x1, n, i;


printf("Digite o numero e o valor inicial\t");
scanf("%lf %lf", &n, &x);


while (x*x != n){
   if ((x == 0 )|| (n<0)) {
       printf("Valor invalido");
       return 0;
   }
   x1 = x;
   x = (x - (((x*x)-n)/(2*x)));
   if ((abs(x1-x))<(1/1000000.0)) break;
}
if(x<0) x = (x -1);
i = sqrt(n);


printf("O numero eh: %lf \nSua raiz quadrada eh: %lf, %lf - valor obtido pelo metodo de Newton\n", n, i, x);
}