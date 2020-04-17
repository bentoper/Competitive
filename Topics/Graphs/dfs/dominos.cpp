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
#define MAXN 444

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int comp = 0, n, m, visited[112345];

stack<int> topsort;

vi adj[112345];

void dfs(int v, int mode){
	visited[v] = 1;
	for(auto x: adj[v]){
		if(visited[x]) continue;
		dfs(x, mode);
	}
	if(mode) topsort.push(v);
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		frr(i, n){
			visited[i] = 0;
			adj[i].clear();
		}
		fr(i, m){
			int a, b; scanf("%d%d", &a, &b);
			adj[a].pb(b);
		}
		comp = 0;
		frr(i, n){
			if(visited[i]) continue;
			dfs(i, 1);
		}
		frr(i, n){
			visited[i] = 0;
		}
		while(!topsort.empty()){
			int i = topsort.top(); 
			if(!visited[i]) {dfs(i, 0); comp++;} 
			topsort.pop();
		}

		printf("%d\n", comp);
	}
}