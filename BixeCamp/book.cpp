#include <bits/stdc++.h>
using namespace std;

int main(){
    int sizes, n, book[10000], permutation[10000];
    cin >> sizes >> n;
    for(int i = 0; i < sizes; i++){
        int c;
        cin >> c;
        book[i] = c;
    }
    for(int i = 0; i < n; i++){
        int a, b, c, p = 0;
        cin >> a >> b >> c;
        if(c >= a && c <= b){
            for(int i = a - 1; i < b; i++){
                if(book[i] < book[c - 1]) p++;
            }
            if(book[c - 1] == book[a - 1 + p]) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "Yes\n";
    }
}
