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
#define MAX_SIEVE 2002


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



int n; 

int main(){
	cin >> n;
	
	crivo();

	if(!mark[n]){
		cout << n << endl;
		frr(i, n){
			if(i != n-1) cout << i << " " << (i + 1)%n << endl;
			else cout << n - 1 << " " << n << endl;
		}
	}

	else{

		int cnt = prim[lower_bound(all(prim), n) - prim.begin()];

		cout << cnt << endl;
		frr(i, n){
			if(i != n-1) cout << i << " " << (i + 1)%n << endl;
			else cout << n - 1 << " " << n << endl;
		}
		frr(i, cnt - n){
			cout << i << " " << n - i << endl;
		}

	}

}








