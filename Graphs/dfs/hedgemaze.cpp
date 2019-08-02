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
#define MAXN 11234

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int low[MAXN], pre[MAXN], clk = 0;

int pai[MAXN], peso[MAXN];


int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(peso[x] > peso[y]) swap(x, y);

	pai[x] = y;
	if(peso[x] == peso[y]) peso[y]++;

}

struct Edges{
	int x, y, id;
};

vector<Edges> edges[MAXN];

int dfs(int v, int p, int id){

	pre[v] = clk++;
	low[v] = pre[v];

	for(auto e: edges[v]){
		int x = e.y;
		if(e.id == id) continue;
		if(pre[x] == -1){
			dfs(x, v, e.id);
			low[v] = min(low[v], low[x]);
			if(pre[x] == low[x]){
				join(x, v);
			}
		}
		else low[v] = min(low[v], pre[x]);
	}
}

int main(){

	int R, C, Q;
	scanf("%d%d%d", &R, &C, &Q);
	while(R != 0){
		int csi = 0;
		clk = 0;
		frr(i, R){
			pai[i] = i;
			peso[i] = 1;
			edges[i].clear();
			pre[i] = -1;
		}
		fr(i, C){
			int a, b; scanf("%d%d", &a, &b);
			edges[a].pb({a, b, csi});
			edges[b].pb({b, a, csi++});
		}
		frr(i, R){
			if(pre[i] == -1) dfs(i, i, -1);
		}
		fr(i, Q){
			int a, b; scanf("%d%d", &a, &b);
			if(find(a) == find(b)) printf("Y\n");
			else printf("N\n");
		}
		printf("-\n");
		scanf("%d%d%d", &R, &C, &Q);
	}

}
