//https://codeforces.com/contest/906/problem/D
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
#define MAX_SIEVE 1123456


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<ll> prim;
ll mark[MAX_SIEVE], n, m, q, rock[MAX_SIEVE];
vector<ll> precalc, pow2;	

int li[MAX_SIEVE];


int sz;

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

ll fastxp(ll a, ll x, ll mod){
	if(x == 0) return 1;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2, mod)*((x&1)?a:1))%mod;
}


ll solve(int l, int r, int pos){

	ll mod = precalc[pos];

	if(l == r) return rock[l];

	if(rock[l]%mod == 0) return 0;

	if(rock[l]%mod == 1) return 1;

	int val = r - l;

	if(val == 1) return fastxp(rock[l]%mod, rock[r], mod);

	ll x = precalc[pos+1];

	int modzin = log2(mod);

	if(rock[l+1] >= modzin || val >= 6){
		ll ans = solve(l + 1, r, pos + 1);		
		return fastxp(rock[l]%mod, x + ans%x, mod);
	}
	
	for(int i = l + 1; i <= r; i++){
		if(rock[i] >= modzin){
			ll ans = solve(l + 1, r, pos + 1);		
			return fastxp(rock[l]%mod, x + ans%x, mod);			
		}  
	}

	ll plc = 1;	
	for(int i = 0; i < rock[r]; i++){
		plc *= rock[r-1];
		if(plc >= modzin){
			ll ans = solve(l + 1, r, pos + 1);		
			return fastxp(rock[l]%mod, x + ans%x, mod);			
		}
	}

	if(val == 2){
		return fastxp(rock[l]%mod, plc, mod);
	}

	ll plc2 = 1;

	for(int i = 0; i < plc; i++){
		plc2 *= rock[r - 2];
		if(plc2 >= modzin){
			ll ans = solve(l + 1, r, pos + 1);		
			return fastxp(rock[l]%mod, x + ans%x, mod);			
		}
	}

	if(val == 3) return fastxp(rock[l]%mod, plc2, mod);

	ll plc3 = 1;

	for(int i = 0; i < plc2; i++){
		plc3 *= rock[r - 3];
		if(plc3 >= modzin){
			ll ans = solve(l + 1, r, pos + 1);		
			return fastxp(rock[l]%mod, x + ans%x, mod);			
		}
	}		

	if(val == 4) return fastxp(rock[l]%mod, plc3, mod);

	ll plc4 = 1;

	for(int i = 0; i < plc3; i++){
		plc4 *= rock[r - 4];
		if(plc4 >= modzin){
			ll ans = solve(l + 1, r, pos + 1);		
			return fastxp(rock[l]%mod, x + ans%x, mod);			
		}
	}

	return fastxp(rock[l]%mod, plc4, mod);	

}


int main(){
	
	crivo();

	scanf("%lld%lld", &n, &m); 

	ll plc = 2;

	int i = 0;

	pow2.pb(plc);

	frr(i, n){
		scanf("%lld", &rock[i]);
		li[i] = INF;
	}

	li[n+1] = INF;

	for(int i = n; i > 0; i--){
		if(rock[i] == 1) li[i] = i;
		else li[i] = li[i+1];
	}

	precalc.pb(m);

	while(m != 1){
		precalc.pb(tot(m));
		m = tot(m);
	}

	m = precalc[0];
	
	int q;
	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);

		if(li[l] < r) r = li[l] - 1;
		if(r == l) printf("%lld\n", rock[l]%m);
		else printf("%lld\n", solve(l, r, 0)%m);
	}

}
