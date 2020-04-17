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
#define MAXN 1123

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int low[MAXN], pre[MAXN], clk = 0, fodeu = 0, n, m, qnt = 0;

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
				fodeu = 1;
			}
		}
		else low[v] = min(low[v], pre[x]);
		if(fodeu) break;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	while(n != 0){
		fodeu = 0, clk = 0, qnt = 0;
		frr(i, n){
			edges[i].clear();
			pre[i] = -1;
		}
		fr(i, m){
			int a, b; scanf("%d%d", &a, &b);
			edges[a].pb({a, b, qnt});
			swap(a, b);
			edges[a].pb({a, b, qnt++});
		}
		dfs(1, 1, -1);
		if(fodeu){
			printf("N\n");
		}
		else printf("S\n");
		scanf("%d%d", &n, &m);
	}
}
