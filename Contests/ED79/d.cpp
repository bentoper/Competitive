#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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
const int N = 2e6 + 10;
const ll mod = 998244353;

ll fastxp(ll a, int x){
    if(a==1ll) return 1ll;
	if(x == 0) return 1ll;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2)*((x&1)?a:1))%mod;
}

ll check(ll a){
    if(a >= mod) a %= mod;
    while(a < 0) a += mod;
    return a;
}

ll n, qnt[N], sz[N];
vi k[N];

int main(){
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++){
        scanf("%lld", &sz[i]);
        for(ll j = 0; j < sz[i]; j++){
            rvr(a);
            k[i].pb(a);
            qnt[a]++;
        }
    }
    ll ans = 0;
    ll invn = fastxp((n*n)%mod, mod - 2);
    for(ll i = 0; i < n; i++){
        ll invk = fastxp(sz[i], mod - 2);
        ll prod = invn*invk;
        prod = check(prod);
        for(auto p: k[i]){
            ll plc = prod*qnt[p];
            plc = check(plc);
            ans += plc;
            ans = check(ans);
        }
    }
    printf("%lld\n", check(ans));
}
