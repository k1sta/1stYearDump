#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;

    cin >> s;

    n = size(s);

    for(int i = 0; i < n; i++){

        if(s[i] == '0'){
            cout << '1';
        } else{
            cout << '0';
        }
    }
    cout << endl;

}
