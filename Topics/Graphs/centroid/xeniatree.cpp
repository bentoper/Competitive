//https://codeforces.com/contest/342/problem/E
//Code inspired by macacário github@splucs/Competitive-Programming
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

int clevel[MAXN], cpar[MAXN], sz[MAXN], dist[MAXN];
vector<int> centree[MAXN];
vector<int> adj[MAXN];
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
		dist[i] = INF;
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
	dist[u] = 0;
	int par = cpar[u]; 
	while(par != -1){
		int lcaa = lca(par, u);
		dist[par] = min(distance(u, lcaa) + distance(lcaa, par), dist[par]);
		par = cpar[par];
	}
}

int query(int u){
	int par = cpar[u]; 
	while(par != -1){
		int lcaa = lca(u, par);
		dist[u] = min(dist[u], dist[par] + distance(u, lcaa) + distance(par, lcaa));
		par = cpar[par];
	}

	return dist[u];	
}


int main(){
	cin >> n >> m;
	fr(i, n - 1){
		int a,b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	ms(memo, -1);
	ms(hgt, -1);

	hgt[1] = 0;

	centroiddecomposition(1);

	dfslca(1);

	update(1);

	fr(i, m){
		int a, b; cin >> a >> b;
		if(a == 1) update(b);
		else cout << query(b) << "\n";
	}

}
