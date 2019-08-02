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
#define MAXN 123

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int clk = 0, n, m, dist[MAXN];

stack<int> topsort;

vi adj[MAXN];


void dfs(int v, int mode){
	dist[v] = 1;
	for(auto x: adj[v]){
		if(dist[x]) continue;
		dfs(x, mode);
	}
	if(mode) topsort.push(v);
}

void distcalc(int v){

}

int main(){
	scanf("%d", &n);
	while(n != 0){
		frr(i, n){
			dist[i] = 0;
			adj[i].clear();
		}
		
		int s; scanf("%d", &s);
		int p, q; scanf("%d%d", &p, &q);
		while(p != 0){
			adj[p].pb(q);
			scanf("%d%d", &p, &q);
		}
		
		dfs(s, 1);

		frr(i, n){
			dist[i] = 0;
		}

		int max_dist = 0, idx = s;

		while(!topsort.empty()){
			int i = topsort.top();  
			topsort.pop();
			for(auto x: adj[i]){
				if(dist[i] + 1 > dist[x]){
					dist[x] = dist[i] + 1;
					if(dist[x] == max_dist){
						idx = min(idx, x);
					}
					else if(dist[x] > max_dist){
						idx = x;
						max_dist = dist[x];
					}
				}
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++clk, s, max_dist, idx);
		scanf("%d", &n);
	}
}