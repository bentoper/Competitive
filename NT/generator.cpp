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
vll prim;
int primes[100000001];

void crivo(){
	for(ll i = 2; i <= 100000; i++){
		if(!primes[i]){
			prim.pb(i);
			for(ll j = i*i; j <= 100000; j += i) primes[j] = 1;
		}
	}
}


int main(){
	scanf("%lld", &N);
	crivo();
	ll tam = prim.size();
	fr(j, N){
		scanf("%lld%lld", &low, &high);
		for(ll start = low; start <= high; start++){
			int i = 0;
			while(prim[i]*prim[i] <= start && start%prim[i] != 0) i++;
			if(start%prim[i] != 0 && start != 1) printf("%lld\n", start);
			if(start == 2) printf("%lld\n", start);
		}
		gnl;
	}
}
