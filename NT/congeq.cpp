//https://codeforces.com/contest/919/problem/E
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
const int MAX_SIEVE = 1e7;

vector<int> prim;
int mark[MAX_SIEVE];
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i);
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

ll fastxp(ll a, int x, ll mod){
	if(x == 0) return 1;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2, mod)*((x&1)?a:1))%mod;
}

ll tot(ll x){
	ll ans = x;
	for(auto z: prim){
		if(z*z > x) break;
		if(x%z == 0){
			while(x%z == 0){
				x /= z;
			}
			ans -= ans/z;
		}
	}
	if(x != 1) ans -= ans/x;
	return ans;
}

int main(){
    ll a, b, p, x; scanf("%lld%lld%lld%lld", &a, &b, &p, &x);
    ll ans = 0;
    ll prod = p*p - p;
    ll rmult = (p*fastxp(p, tot(p-1)-1, p-1))%prod;
	ll barmult = ((p-1)*(fastxp(p-1, p-2, p)))%prod;
    a = fastxp(a, p-2ll, p);
	for(ll r = 0; r <= p-2; r++){
        ll plc = (r*rmult)%prod;
		plc += ((b*fastxp(a, r, p))%p)*barmult;
        plc %= prod;
        if(plc <= x){
            ans += 1ll + (x - plc)/prod;
        }
    }
    printf("%lld\n", ans); 
}
