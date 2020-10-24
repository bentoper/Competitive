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
#define tsts(t) rvr(t); while(t--)


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
const int MOD = 998244353;

ll fastxp(ll x, ll n){
	ll ret = 1;
	while(n){
		if(n&1ll) ret *= x, ret %= MOD;
		x *= x;
        x %= MOD;
		n /= 2ll;
	}
	return ret%MOD;
}

int main(){
    rvr(n); rvr(k);
    vii t(n);
    vii q;
    fr(i, n){
        scanf("%d%d", &t[i].ff, &t[i].ss);
        q.pb(mp(t[i].ff, 0));
        q.pb(mp(t[i].ss, 1));
    }
    vll comb(1, 1);
    for(ll i = k; i <= n; i++){
        comb.pb((((comb[i - k]*i)%MOD)*fastxp(i - (k-1), MOD - 2))%MOD); 
    }
    sort(all(q));
    ll ans = 0;
    int cur = 0;
    for(auto p: q){
        if(p.ss == 1){
            cur--;
            continue;
        }
        if(cur >= k - 1){
            ans += comb[cur - (k-1)];
            ans %= MOD;
        }
        cur++;
    }
    printf("%lld\n", ans);
}
