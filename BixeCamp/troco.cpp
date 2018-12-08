#include <bits/stdc++.h>
using namespace std;

int memo[1000][100001];
int moedas[1000];
int p, n;

bool dp(int i, int rest){
    if(rest == 0) return true;
    if(i == n) return false;
    if(memo[i][rest] == -1){
        memo[i][rest] = dp(i+1, rest) || dp(i+1, rest-moedas[i]);
    }
    return memo[i][rest];
}

int main(){
    cin >> p >> n;
    for(int i = 0; i < n; i++){
            cin >> moedas[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= p; j++) memo[i][j] = -1;
    }
    if(dp(0, p) == true) cout << "S" << endl;
    else cout << "N" << endl;
}
