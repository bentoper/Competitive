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


ll N, high, low;
vll acc, prim;
int primes[1000001];

void crivo(){
	for(ll i = 2; i <= 1000000;i++){
		if(!primes[i]){
			prim.pb(i);
			for(ll j = i*i; j <= 1000000; j+=i) primes[j] = 1;
		}
	}
	ll sz = prim.size();
	fr(i, sz){
		ll aux = prim[i]*prim[i];
		while(aux <= 1000000000000 && aux > 0){
			acc.pb(aux);
			aux*=prim[i]; 
		}
	}
	sort(all(acc));
}


int main(){
	scanf("%lld", &N);
	crivo();
	ll tam = acc.size();
	while(N--){
		scanf("%lld%lld", &low, &high);
		ll start = lower_bound(all(acc), low) - acc.begin();
		ll end = lower_bound(all(acc), high) - acc.begin();
		if(end != tam && acc[end] == high) end++;
		printf("%lld\n", end - start);
	}

}
