#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c = 0;
    cin >> a >> b;
    while((a >= 1 && b >= 1) && !(a == 1 && b == 1)){
        if (a >= b){
            c++;
            a = a - 2;
            b = b - 1;
        }else{
            c++;
            a = a - 1;
            b = b - 2;
        }
    }
    cout << c << endl;
}
