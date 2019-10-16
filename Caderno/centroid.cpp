#define MAXN 212345
#define LMAXN 16

int clevel[MAXN], cpar[MAXN], sz[MAXN];
vector<int> centree[MAXN];
vector<int> adj[MAXN];
int n;

int subsize(int v, int p){

	sz[v] = 1;

	for(auto x: adj[v]) {
		if(x == p || clevel[x] != -1) continue;
		sz[v] += subsize(x, v);
	}

	return sz[v];
}

int findcentroid(int v, int p, int nn){
	for(auto x: adj[v]) {
		if (x != p && clevel[x] < 0 && sz[x] > nn/2){
			return findcentroid(x, v, nn);
		}
	}
	return v;
}

int decompose(int root, int par){
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

int main(){
	
}