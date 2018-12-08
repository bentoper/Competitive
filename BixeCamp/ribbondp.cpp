#include <bits/stdc++.h>
using namespace std;

int memo[4001];
int n, a, b, c;

int dp(int current){
    if(current == 0) return 0;
    if(current < 0) return -8000;
    if(memo[current] == -1){
        memo[current] = max(1 + dp(current - a), max(1 + dp(current - b), 1 + dp(current - c)));

    }
    return memo[current];
}

int main(){
    cin >> n >> a >> b >> c;
    for(int i = 0; i <= n; i++){
       memo[i] = -1;
    }
    cout << dp(n) << endl;
}
