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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vll prim;
int primes[66001];

ll N, ans = 1, blip;

void crivo(ll top){
	for(ll i = 2; i <= top; i++){
		if(!primes[i]){
			prim.pb(i);
			for(ll j = i*i; j <= top; j += i) primes[j] = 1;
		}
	}
}

void solve(ll x){
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
}

int main(){
	crivo(66000);
	blip = prim.size();
	while(scanf("%lld", &N) == 1){
		ans = N;
		solve(N);	
		if(ans == 1) printf("1\n");
		else printf("%lld\n", ans/2);
	}
}
