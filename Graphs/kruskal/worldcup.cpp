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
#define MAX 101

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


// pai inicializa com p[i] = i e peso = 0, qtd = 1;
int pai[MAX], peso[MAX], qtd[MAX];

int n, f, r;
ll mst_size;

struct aresta{
	int x;
	int y;
	int w;
};

aresta rodovias[5001], ferrovias[5001];

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
		qtd[px] += qtd[py];
	}
	else{
		pai[px] = py;
		if(peso[px] == peso[py]) peso[py]++;
		qtd[py] += qtd[px];
	}

}


int main(){
	scanf("%d%d%d", &n, &f, &r);
	frr(i, n) pai[i] = i;
	ms(qtd, 1);
	fr(i, f){
		scanf("%d%d%d", &ferrovias[i].x, &ferrovias[i].y, &ferrovias[i].w);
	}
	fr(i, r){
		scanf("%d%d%d", &rodovias[i].x, &rodovias[i].y, &rodovias[i].w);
	}

	sort(ferrovias, ferrovias+f, mysort);
	sort(rodovias, rodovias+r, mysort);

	fr(i, f){
		if(find(ferrovias[i].x) != find(ferrovias[i].y)){
			join(ferrovias[i].x, ferrovias[i].y);
			mst_size += ferrovias[i].w;
		}
	}
	fr(i, r){
		if(find(rodovias[i].x) != find(rodovias[i].y)){
			join(rodovias[i].x, rodovias[i].y);
			mst_size += rodovias[i].w;
		}
	}
	printf("%lld\n", mst_size);
}
