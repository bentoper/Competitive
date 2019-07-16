//https://www.spoj.com/problems/CPRIME/
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
#define MAX_SIEVE 100000001

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
int accum[MAX_SIEVE];

	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]){ prim.pb(i); accum[i] = accum[i-1] + 1;}
		else accum[i] = accum[i-1];
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

double solve(int x){
	//dbg(accum[x]); dbg(x/log(x));
	return 100*abs(1.0 - (double)x/(log(x)*(double)accum[x]));
}


int main(){
	fastio;
	crivo();
	int x;
	while(cin >> x && x != 0){
		cout << setprecision(1) << fixed << solve(x) << "\n";
	}

}
