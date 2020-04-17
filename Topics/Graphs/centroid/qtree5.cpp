//https://www.spoj.com/problems/QTREE5/
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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

#define MAXN 212345
#define LMAXN 16

int memo[MAXN][LMAXN + 1];
int hgt[MAXN];

int clevel[MAXN], cpar[MAXN], sz[MAXN], color[MAXN];
vector<int> centree[MAXN];
vector<int> adj[MAXN];
multiset<int> dist[MAXN];
int n, m;

int subsize(int v, int p) {
	sz[v]=1;
	for(auto x: adj[v]) {
		if(x == p || clevel[x] != -1) continue;
		sz[v] += subsize(x, v);
	}
	return sz[v];
}

int findcentroid(int v, int p, int nn) {
	for(auto x: adj[v]) {
		if (x != p && clevel[x] < 0 && sz[x] > nn/2){
			return findcentroid(x, v, nn);
		}
	}
	return v;
}

int decompose(int root, int par) {
	subsize(root, -1);
	int u = findcentroid(root, -1, sz[root]);
	cpar[u] = par;
	clevel[u] = par >= 0 ? clevel[par]+1 : 0;
	sz[u] = 1;
	for(auto v: adj[u]) {
		if (v != par && clevel[v] < 0) {
			v = decompose(v, u);
			centree[u].push_back(v);
			sz[u] += sz[v];
		}
	}
	return u;
}

int centroiddecomposition(int root) {
	for(int i = 1; i <= n; i++){
		sz[i] = 0;
		clevel[i] = -1;
		centree[i].clear();
		color[i] = 0;
	}
	return decompose(root, -1);
}

void dfslca(int v){
	
	for(auto filho : adj[v]){
	
		if(hgt[filho] != -1)	continue;
	
		memo[filho][0]=v;		//seta o pai do cara
		hgt[filho]=hgt[v]+1;
		
		for(int i=1;i<LMAXN;i++)	
			if(memo[filho][i-1] != -1) memo[filho][i]=memo[memo[filho][i-1]][i-1];
								//gera a sparse table na propria dfs (dependencias ja estao calculadas, por inducao)
		dfslca(filho);
	}

}

int lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);		//quero que a seja o cara mais profundo na arvore

	for(int i=LMAXN-1; i>=0; i-- ){						//bota a e b na mesma altura
		if(memo[a][i] != -1 && hgt[ memo[a][i] ] >= hgt[b])	a=memo[a][i];	//vou subir o a ate ele ficar no mesmo nivel do b
	}

	if(a==b)	return a;	//se forem iguais, retorna o LCA

	for(int i=LMAXN-1; i>=0; i--){	//vai pulando ate ficarem ambos a e b um nivel antes do LCA
		
		if(memo[a][i]!=-1 && memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}

	}

	return memo[b][0];	//sobe um nivel e retorna o lca

}

int distance(int a, int b){
	return abs(hgt[b] - hgt[a]);
}


void update(int u){
	color[u] = 1;
	dist[u].insert(0);
	int par = cpar[u]; 
	while(par != -1){
		int lcaa = lca(par, u);
		dist[par].insert(distance(u, lcaa) + distance(lcaa, par));
		par = cpar[par];
	}
}

void unupdate(int u){
	color[u] = 0;
	auto it = dist[u].find(0);
	dist[u].erase(it);
	int par = cpar[u]; 
	while(par != -1){
		int lcaa = lca(par, u);
		it = dist[par].find(distance(u, lcaa) + distance(lcaa, par)); 
		dist[par].erase(it);
		par = cpar[par];
	}
}

int query(int u){
	int base;
	if(dist[u].empty()) base = INF;
	else base = *(dist[u].begin());
	int par = cpar[u]; 
	while(par != -1){
		int lcaa = lca(u, par);
		if(dist[par].empty()){
			par = cpar[par];
			continue;	
		}
		base = min(base, *(dist[par].begin()) + distance(u, lcaa) + distance(par, lcaa));
		par = cpar[par];
	}

	if(base == INF) base = -1;

	return base;	
}


int main(){
	cin >> n;
	fr(i, n - 1){
		int a,b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	cin >> m;

	ms(memo, -1);
	ms(hgt, -1);

	hgt[1] = 0;

	centroiddecomposition(1);

	dfslca(1);

	fr(i, m){
		int a, b; cin >> a >> b;
		if(a == 0){
			if(color[b]) unupdate(b);
			else update(b);
		}
		else cout << query(b) << "\n";
	}

}
