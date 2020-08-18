#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

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
const ll MOD = 1e9 + 7;

ll fastxp(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return a;
    if(a == 1ll) return 1ll;
	return (fastxp((a*a)%MOD, x/2)*((x&1ll)?a:1ll))%MOD;
}

int main(){
    //freopen("galactic.in", "r", stdin);
    rvr(t);
    while(t--){
    ll n, k; scanf("%lld%lld", &n, &k);
    if(k == 1){
        printf("1\n");
        continue;
    }
    if(k > n) printf("0\n");
    else if(k == n){
        ll ans = 1;
        frr(i, n){
            ans *= (ll)i;
            if(ans < 0) ans += MOD;
            ans %= MOD;
            if(ans < 0) ans += MOD;
        }
        printf("%lld\n", ans%MOD);
    }
    else{
        ll ans = 1;
        frr(i, n - k){
            ans *= (ll)(n - (ll)(i-1));
            if(ans < 0) ans += MOD;
            ans %= MOD; //n-k ultimos de n!
            if(ans < 0) ans += MOD;
            ans *= fastxp(i, MOD - 2ll), ans %= MOD; //(n-k)!²
            if(ans < 0) ans += MOD;
        }
        ans *= fastxp(k, n-k);
        ans %= MOD;
        if(ans < 0) ans += MOD;
        printf("%lld\n", ans%MOD);
    }
    }

}
