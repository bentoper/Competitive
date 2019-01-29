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
#define MAX 10000

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[MAX], peso[MAX], qnt[MAX];

int n, m, mst_size;

struct aresta{
	int x;
	int y;
	int w;
};

aresta arestas[MAX];
vector<aresta> mst;

bool mysort(aresta a, aresta b){ return a.w < b.w; }


int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	int px = find(x);
	int py = find(y);

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
	scanf("%d", &n);
	int count = 1;
	while(n != 0){
		scanf("%d", &m);
		frr(i, n) pai[i] = i;
		ms(peso, 0);
		ms(qnt, 1);
		fr(i, m){
			scanf("%d%d%d", &arestas[i].x, &arestas[i].y, &arestas[i].w);
		}
		sort(arestas, arestas+m, mysort);
		fr(i, m){
			if(find(arestas[i].x) != find(arestas[i].y)){
				mst.pb(arestas[i]);
				join(arestas[i].x, arestas[i].y);
			}
		}
		printf("Teste %d\n", count);
		count++; 
		int sz = mst.size();
		fr(i, sz){
			if(mst[i].x > mst[i].y) swap(mst[i].x, mst[i].y);
			printf("%d %d\n", mst[i].x, mst[i].y);
		}
		gnl;
		mst.clear();
		scanf("%d", &n);
	}
	return 0;
}
