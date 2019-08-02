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


int clk = 0, n, m, clko = 0;

int low[MAXN], pre[MAXN], qnt;

bool art[MAXN];

struct Edges{
	int x, y, id;
};

vi bridges, articles;

vector<Edges> edges[MAXN];

int dfs(int v, int p, int id){

	pre[v] = clk++;
	low[v] = pre[v];
	bool forw = false;
	for(auto e: edges[v]){
		int x = e.y;
		if(e.id == id) continue;
		if(pre[x] == -1){
			dfs(x, v, e.id);
			low[v] = min(low[v], low[x]);
			if(pre[x] == low[x]){
				bridges.pb(e.id);
			}
			if(v != p ? low[x] >= pre[v] : forw){
				if(!art[v]) articles.pb(v);
				art[v] = true;
			}
			forw = true;
		}
		else low[v] = min(low[v], pre[x]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	while(n != 0){
		qnt = 0;
		frr(i, n) {pre[i] = -1; art[i] = false;}
		fr(i, m){
			int a, b; scanf("%d%d", &a, &b);
			edges[a].pb({a, b, qnt});
			edges[b].pb({b, a, qnt++});
		}
		dfs(1, 1, -1);
		printf("Teste %d\n", ++clko);
		if(articles.size() > 0) {
			sort(all(articles));
			int vaca = articles.size();
			fr(i, vaca){
				printf("%d", articles[i]);
				if(i == vaca-1) printf("\n");
				else printf(" ");
			}
			articles.clear();
		}
		else{
			printf("nenhum\n");
		}
		frr(i, n){
			edges[i].clear();
		}
		printf("\n");
		scanf("%d%d", &n, &m);
	}

}
