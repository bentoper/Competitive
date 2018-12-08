#include <bits/stdc++.h>
using namespace std;

int memo[50][1001][1251];
int frases[50], desculpa[50];
int carac, n;

int dp(int i, int rest, int sum){
    if(carac - rest < 0) return 0;
    if(carac - rest == 0) return sum;
    if(i == n) return sum;
    if(memo[i][rest][sum] == -1){
        memo[i][rest][sum] = max(dp(i+1, rest+frases[i], sum + desculpa[i]), dp(i+1, rest, sum));
    }
    return memo[i][rest][sum];
}

int main(){
    cin >> carac >> n;
    int c = 1;
    while(carac != 0 and n != 0){
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> frases[i] >> desculpa[i];
            sum += desculpa[i];
            for(int j = 0; j <= carac; j++){
                for(int k = 0; k <= sum; k++) memo[i][j][k] = -1;
            }
        }
        cout << "Teste " << c << endl << dp(0, 0, 0) << endl;
        c++;
        cin >> carac >> n;
    }
}
