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
#define MAXN 212345

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi edges[MAXN];

stack<int> nodes;

int outdeg[MAXN], indeg[MAXN], low[MAXN], pre[MAXN], comp[MAXN];

int clk = 0, n, m, numscc = 0;

void dfs(int v){
	
	pre[v] = clk++;
	low[v] = pre[v];

	nodes.push(v);

	for(auto x: edges[v]){
		if(pre[x] == -1){
			dfs(x);
		}
		low[v] = min(low[v], low[x]);
	}

	if(low[v] == pre[v]){

		while(true){

			int j = nodes.top();
			nodes.pop();
			comp[j] = numscc;
			low[j] = MAXN;

			if(j == v || nodes.empty()) break;
		}
		numscc++;		
	}
}


int main(){
	int t; scanf("%d", &t);
	while(t--){
		clk = 0;
		scanf("%d%d", &n, &m);
		frr(i, n){
			pre[i] = -1;
			outdeg[i] = 0;
			indeg[i] = 0;
			low[i] = -1;
			numscc = 0;
			comp[i] = 0;
			edges[i].clear();
		}

		fr(i, m){
			int a, b; scanf("%d%d", &a, &b);
			edges[a].pb(b);
		}

		frr(i, n) if(pre[i] == -1) dfs(i);

		int sinks = 0, src = 0;

		frr(i, n){
			for(auto j: edges[i]){
				if(comp[i] != comp[j]){
					indeg[comp[j]]++;
					outdeg[comp[i]]++;
				}
			}
		}

		fr(i, numscc){
			if(indeg[i] == 0) src++;
			if(outdeg[i] == 0) sinks++;	
		}

		if(numscc == 1) printf("0\n");
		else printf("%d\n", max(sinks, src));	
	}
}





















