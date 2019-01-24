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
const ll SIEVE_MAX = 1000000000;

int A, B, C, D;

vll prim;
int primes[100001];

void crivo(){
	for(ll i = 2; i*i <= SIEVE_MAX;i++){
		if(!primes[i]){
			prim.pb(i);
			for(ll j = i*i; j*j <= SIEVE_MAX; j+=i) primes[j] = 1;
		}
	}
}

void solve(int x){
	for(int i = prim.size() - 1; i >= 0; i--){
		int z = prim[i];
		int aux = x/z;
		while(x%z == 0 && aux%A == 0 && D%aux != 0 && aux != 1){
			aux /= z;
			x /= z;
		}
	}
	C = x;
}


int main(){
	scanf("%d%d%d%d", &A, &B, &C, &D);
	if(C%A != 0 || A%B == 0 || C == D){
		 printf("-1\n");
		 return 0;
	}
	crivo();
	solve(C);
	if(C%B != 0 && C%A == 0 && D%C != 0) printf("%d\n", C);
	else printf("-1\n");
}
