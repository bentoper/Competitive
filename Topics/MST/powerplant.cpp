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
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAX 201

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[201], peso[201], qnt[201], on[201];

ll mst_size;
int n, m, k;

struct aresta{
	int x;
	int y;
	int w;
};

aresta arestas[22000];
vector<aresta> mst;

bool mysort(aresta a, aresta b){ return a.w < b.w; }


int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	int px = find(x);
	int py = find(y);
	if(on[px]) on[py] = 1;
	if(on[py]) on[px] = 1;

	if(px == py) return;

	if(peso[px] > peso[py]){
		pai[py] = px;
		qnt[px] += qnt[py];
	}
	else{
		pai[px] = py;
		if(peso[px] == peso[py]) peso[py]++;
		qnt[py] += qnt[px];
	}

}


int main(){
	rvr(t); int count = 1;
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		frr(i, n){
			pai[i] = i;
			qnt[i] = 1;
			peso[i] = 1;
			on[i] = 0;
		}
		mst_size = 0;
		fr(i, k){
			rvr(aux);
			on[aux] = 1;
		}
		fr(i, m){
			scanf("%d%d%d", &arestas[i].x, &arestas[i].y, &arestas[i].w);
		}
		sort(arestas, arestas+m, mysort);
		fr(i, m){
			int a = find(arestas[i].x);
			int b = find(arestas[i].y);
			if((!on[a] || !on[b]) && (a != b)){
				join(a, b);
				mst_size += arestas[i].w;
			}
		}
		printf("Case #%d: %lld\n", count++, mst_size);
	}

}
