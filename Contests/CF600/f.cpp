#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])

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
const ll llINF = 1e17;
const int MAX = 1e5 + 1;
const int LMAX = 20;

struct edge{
    int u;
    int v;
    ll w;
};

// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[MAX], peso[MAX];
int n, m, k, q;

ll dist[MAX];

int memo[MAX][LMAX + 1], hgt[MAX];

ll maxar[MAX][LMAX + 1];

edge edges[3*MAX];

vi adj[MAX];

int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(peso[x] > peso[y]) swap(x, y);

	pai[x] = y;
	if(peso[x] == peso[y]) peso[y]++;

}


void dijkstra(){
    set<pair<ll, int>> S;
    frr(i, k) S.insert(mp(0, i));
    while(!S.empty()){
        int v = (*S.begin()).second;
        S.erase(S.begin());
        for(auto e: adj[v]){
            int u = edges[e].u + edges[e].v - v;
            if(dist[u] > dist[v] + edges[e].w){
                if(dist[u] != llINF) S.erase(mp(dist[u], u));
                dist[u] = dist[v] + edges[e].w;
                S.insert(mp(dist[u], u));
            }
        }
    }
}

void dfslca(int v){
	
	for(auto z : adj[v]){

        int filho = edges[z].u + edges[z].v - v;

		if(hgt[filho] != -1)	continue;
	
		memo[filho][0]=v;		//seta o pai do cara
		hgt[filho]=hgt[v]+1;
        maxar[filho][0] =edges[z].w;
		
		for(int i=1;i<LMAX;i++){ 	
			if(memo[filho][i-1] != -1){
                memo[filho][i]=memo[memo[filho][i-1]][i-1];
                maxar[filho][i] = max(maxar[memo[filho][i-1]][i-1], maxar[filho][i-1]);
            }
        }
		dfslca(filho);
	}

}

ll lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);		//quero que a seja o cara mais profundo na arvore

    ll mxar = -1;

	for(int i=LMAX-1; i>=0; i-- ){						//bota a e b na mesma altura
		if(memo[a][i] != -1 && hgt[memo[a][i]] >= hgt[b])	mxar = max(mxar, maxar[a][i]), a = memo[a][i];	//vou subir o a ate ele ficar no mesmo nivel do b
	}

	if(a==b)	return mxar;	//se forem iguais, retorna o LCA

	for(int i=LMAX-1; i >= 0; i--){	//vai pulando ate ficarem ambos a e b um nivel antes do LCA
		if(memo[a][i] == -1) continue;
        if(memo[b][i] == memo[a][i]) continue;
        mxar = max(mxar, maxar[a][i]);
        mxar = max(mxar, maxar[b][i]);
        a = memo[a][i];
        b = memo[b][i];
	}

	return max(mxar, max(maxar[b][0], maxar[a][0]));	//sobe um nivel e retorna o lca

}

bool edgecomp(edge a, edge b){
    if(a.w < b.w) return 1;
    return 0;
}


int main(){
    ms(memo, -1);
    ms(hgt, -1);
    hgt[1] = 0;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    fr(i, m){
        rvr(x); rvr(y);
        ll w; scanf("%lld", &w);
        edges[i] = {x, y, w};
        adj[x].pb(i);
        adj[y].pb(i);
    }
    frr(i, n){
        if(i <= k) dist[i] = 0;
        else dist[i] = llINF;
        pai[i] = i;
        peso[i] = 1;
    }
    dijkstra();
    fr(i, m){
        ll plc = dist[edges[i].u] + dist[edges[i].v] + edges[i].w;
        edges[i] = {edges[i].u, edges[i].v, plc};

    }
    sort(edges, edges+m, edgecomp);
    frr(i, n){
        adj[i].clear();
    }
    int ar = 0;
    fr(i, m){
        int u = edges[i].u, v = edges[i].v;
        if(find(u) != find(v)){
            join(u, v);
            adj[u].pb(i);
            adj[v].pb(i);
            ar++;
        }
        if(ar == n-1) break;
    }
    dfslca(1);
    while(q--){
        int u, v; scanf("%d%d", &u, &v);
        printf("%lld\n", lca(u, v));
    }
}
