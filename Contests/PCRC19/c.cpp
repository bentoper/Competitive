#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int mod = 998244353;
const int N = 1e3 + 1;

ll memo[N][N], a[N], cnt[N];
int k, n; 

ll dp(int i, int left, int peguei){
    if(left == 0) return peguei;
    if(n - i < left) return 0;
    if(memo[i][left] != -1) return memo[i][left];
    ll& pd = memo[i][left];

    pd = ((cnt[i]*dp(i + 1, left - 1, 1))%mod + dp(i + 1, left, 0))%mod;

    return pd;

}


ll fastxp(ll a, int x, int mod){
	if(x == 0) return 1;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2, mod)*((x&1)?a:1))%mod;
}

int main(){
    scanf("%d%d", &n, &k);
    ms(memo, -1);
    map<int, int> M;
    fr(i, n){
        rvr(a);
        M[a]++;
    }
    int i = 0;
    for(auto p: M){
        cnt[i] = p.second;
        i++;
    }
    n = i;
    printf("%lld\n", dp(0, k, 0));
}
