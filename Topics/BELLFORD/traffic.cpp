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

struct edge{
	int a;
	int b;
	int w;
};

int n, m, dist[333], cnt = 1, busy[333], pre[333], trued[333];
vector<edge> edges;

void bf(int root){
	dist[root] = 0;
	int x;
	for(int i = 0; i < 2*n; i++){
		x = -1;
		for(auto e: edges){
			if(dist[e.a] < INF){
				if(dist[e.b] > dist[e.a] + e.w){
					dist[e.b] = max(-INF, dist[e.a] + e.w);
					trued[e.b] = dist[e.b];
					if(i >= n) trued[e.b] = 0; 
					x = e.b;
					pre[e.b] = e.a;					
				}
			}
		}
	}
}

int main(){
	while(scanf("%d", &n) == 1){
		ms(dist, INF);
		ms(trued, INF);
		frr(i, n){
			scanf("%d", &busy[i]);
		}
		scanf("%d", &m);
		fr(i, m){
			rvr(sor); rvr(dest);
			int op = (busy[dest] - busy[sor]);
			op *= op*op;
			edges.pb((edge){sor, dest, op});
		}
		if(n > 0) bf(1);
		rvr(q);
		printf("Set #%d\n", cnt++);
		fr(i, q){
			rvr(aux);
			if(trued[aux] < 3 || trued[aux] == INF) printf("?\n");
			else printf("%d\n", dist[aux]);
		}
		edges.clear();
	}
}
