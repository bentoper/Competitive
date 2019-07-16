//https://codeforces.com/gym/101550/attachments
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
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAX_SIEVE 1000000

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<int> prim;
int mark[MAX_SIEVE];

ll n, m;
	
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

ll solve(ll a, ll b){

	//dbg(a); dbg(b);   
	
	if(b == 1) return 0;

	if(a == 5) return fastxp(a, 262144, b);
	if(a == 4) return fastxp(a, 9, b);
	if(a == 3) return fastxp(a, 2, b);
	if(a <= 2) return a%b;

	ll x = tot(b);

	return fastxp(a, x + solve(a-1, x), b);

}

int main(){
	scanf("%lld%lld", &n, &m);
	crivo();
	printf("%lld\n", solve(n, m));
}
