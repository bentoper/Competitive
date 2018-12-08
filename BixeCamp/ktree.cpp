#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int modulo = 1e9+7;

int n, d, k;
int memo[101][101];

int dp(int left, int required){
    if(left < 0 || (left == 0 && required == 0)) return 0;
    if(left == 0 && required) return 1;
    if(memo[left][required] == -1){
        ll sum = 0;
        frr(i, k){
            if(i >= d) sum += dp(left - i, required + 1);
            else sum += dp(left - i, required);
        }
        memo[left][required] = sum%modulo;
    }

    return memo[left][required];
}

int main(){
    cin >> n >> k >> d;
    fr(i, 101){
        fr(k, 101) memo[i][k] = -1;
    }
    cout << dp(n, 0) << endl;
}
