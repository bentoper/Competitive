#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl



typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll modulo = 1000000007;

ll memo[2][10000001], n;

ll dp(ll left){
    memo[0][0] = 1;
    memo[1][0] = 0;
    memo[0][1] = 0;
    memo[1][1] = 1;
    for(ll i = 2; i <= left; i++){
        memo[0][i] = (3*memo[1][i-1])%modulo;
        memo[1][i] = (2*memo[1][i-1] + memo[0][i-1])%modulo;
        //dbg(i); dbg(memo[0][i]); dbg(memo[1][i]);
    }
    return memo[0][left];
}

int main(){
    cin >> n;
    fr(i, n+1) fr(j, 2) memo[j][i] = -1;
    cout << dp(n) << endl;
}
