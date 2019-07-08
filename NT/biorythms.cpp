//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=697
#include <bits/stdc++.h>
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
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAX_SIEVE 3000


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi prim;
int mark[MAX_SIEVE];

ll p, e, i, d;

ll fastxp(ll a, int x, int mod){
	if(x == 0) return 1;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2, mod)*((x&1)?a:1))%mod;
}


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
	ll clk = 0;
	crivo();
	ll base = 23*28*33;

	while(scanf("%lld%lld%lld%lld", &p, &e, &i, &d) && p != -1){

		p %= 23;
		e %= 28;
		i %= 33;

		ll ans = (p*fastxp(base/23, tot(23)-1, base)*base/23)%base + (e*fastxp(base/28, tot(28)-1, base)*base/28)%base + (i*fastxp(base/33, tot(33)-1, base)*base/33)%base;
		ans -= d;
		ans += base;
		ans %= base;

		if(ans == 0) ans = base;

		

		printf("Case %lld: the next triple peak occurs in %lld days.\n", ++clk, ans);  		
	}
}















