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
const int MAX_SIEVE = 1e6 + 2;

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

int c[MAX_SIEVE];

int main(){
	crivo();
    int n, k;
	scanf("%d%d", &n, &k);
	fr(i, n){
		scanf("%d", &c[i]);
	}
	bool wrk = true;
	for(auto p: prim){
		if(p*p > k) continue;
		if(k%p != 0) continue;
		int plc = 1;
		while(k%p == 0){
			k /= p;
			plc *= p;
		}
		bool deu = false;
		fr(i, n){
			if(c[i]%plc == 0){
				deu = true;
				break;
			}
		}
		if(!deu){
			wrk = false;
			break;
		}
	}
	bool deu = false;
	if(k != 1){
		fr(i, n){
			if(c[i]%k == 0){
				deu = true;
				break;
			}
		}
	}
	else deu = true;
	if(!deu) wrk = false;
	if(wrk){
		printf("Yes\n");
	}
	else printf("No\n");
}
