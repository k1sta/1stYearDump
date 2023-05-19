#include<stdio.h>

int f(int a);

int main() {
    int a = 2, b = 3, c = 4;

    f(a) || f(b) && f(c); // 2
    f(a) || (f(b) && f(c)); // 2
    (f(a) || f(b)) && f(c); // 2, 4
    (a > b) && f(a) || f(b) && f(c); // 
    (b > a) && f(a) || f(b) && f(c); // ?
    ((b > a) && f(a) || f(b)) && f(c); // ?

    return 0;
}

int f(int a) {
    printf("%d ", a);
    return a;
}