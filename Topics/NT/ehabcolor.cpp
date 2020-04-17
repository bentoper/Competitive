//https://codeforces.com/contest/1174/problem/C
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
#define gnl cout << "\n"
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

vector<int> prim;
int n;
int mark[112345], color[112345], clk = 0;
	
void crivo(){
	for(int i = 2; i < n + 1; i++){
		if(!mark[i]){ 
			prim.pb(i);
			color[i] = ++clk;
		}
		cout << color[i] << " ";
		for(int p: prim){
			if(i*p >= n + 1) break;
			mark[i*p] = 1;
			color[i*p] = color[p];
			if(i%p == 0) break;
		}
	}
}


int main(){
	cin >> n;
	crivo();
	cout << "\n";
}
