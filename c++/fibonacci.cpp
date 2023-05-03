#include <bits/stdc++.h>

using namespace std;

int fib(int x){

    if (x > 1){

        return fib(x-1) + fib(x-2);

    } else {
        
        return x;
    }
    
}

int main(){
    int x, c = 0;

    cin >> x;

    cout << fib(x) << endl << "Numero de chamadas: " << c;

    return 0;
}
