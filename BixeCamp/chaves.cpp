#include <bits/stdc++.h>
using namespace std;

int main(){
    int countleft = 0, N, errou = 0;
    cin >> N;
    N++;
    while(N--){
        string a;
        getline(cin, a);
        for(char c: a){
            if(c == '{') countleft++;
            else if(c == '}') countleft--;
            if(countleft < 0) errou = 1;
        }
    }
    if(countleft > 0) errou = 1;
    if(errou) cout << "N" << endl;
    else cout << "S" << endl;
}
