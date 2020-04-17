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

#define MAXN 	300000
#define LMAXN	17		//ceil(log2(MAXN))



vector<pii> adj[112345];

pair<pii, int> path;	
int memo[112345][17];
ll dist[112345];
int hgt[112345];
int n;
int q;

void dfs(int v){
	
	for(auto z : adj[v]){
	
		int filho = z.first;

		if(hgt[filho] != -1 && filho != memo[v][0]){
			path = {(pii){v, filho}, z.snd};
			continue;
		}

		if(hgt[filho] != -1)	continue;
	
		memo[filho][0] = v;		//seta o pai do cara
		hgt[filho] = hgt[v]+1;
		dist[filho] = dist[v] + z.second;
		
		for(int i=1;i<LMAXN;i++)	
			if(memo[filho][i-1] != -1) memo[filho][i] = memo[memo[filho][i-1]][i-1];
								//gera a sparse table na propria dfs (dependencias ja estao calculadas, por inducao)
		dfs(filho);
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

ll frederick(int a, int b){
	ll aux = 2*dist[lca(a, b)];
	aux -= dist[a];
	aux -= dist[b];
	aux *= -1;
	return aux;
}

int main(){
	//fastio;
	int t; cin >> t;
	while(t--){
		ms(dist, INF);
		ms(memo, -1);
		ms(hgt, -1);
		cin >> n >> q;
		fr(i, n){
			int a, b, peso;
			cin >> a >> b >> peso;
			adj[a].pb({b, peso});
			adj[b].pb({a, peso});
		}
		dist[1] = 0;
		hgt[1] = 0;
		dfs(1);
		fr(i, q){
			int a, b; cin >> a >> b;
			cout << min(frederick(a, b),  min(frederick(a, path.first.first)+frederick(b, path.first.snd)+path.snd,frederick(b, path.first.first)+frederick(a, path.first.snd)+path.snd)) << endl;
		}
		frr(i, n) adj[i].clear(); 
	}
}