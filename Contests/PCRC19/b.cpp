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

const int MAX_SIEVE = 1e7 + 1;

int m[MAX_SIEVE];

vector<int> prim;
int mark[MAX_SIEVE];
	
void crivo(){
    m[1] = 1;
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), m[i] = -1;
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0){
                m[i*p] = 0;
            }
            else m[i*p] = m[i]*m[p];
		}
	}
}

int main(){
    crivo();
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    ll ans = 0;
    int n = max({a, b, c, d});
    for(ll i = 1; i <= n; i++){
        ll f = max(b/i - (a + (i-1ll))/i + 1ll, 0ll), s = max(0ll, d/i - (c + i - 1ll)/i + 1ll);
        ans += m[i]*f*s;
    }
    printf("%lld\n", ans);
}
