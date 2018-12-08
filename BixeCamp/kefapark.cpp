#include "bits/stdc++.h"
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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int gatinhos = 0;
int visited[100001], catmandu[100001];
vi adj[100001];

void dfs(int s, int cats, int pop){
	visited[s] = 1; int folha = 1;
	if(cats + catmandu[s] > pop) return;
	for(int x: adj[s]){
		if(visited[x]) continue;
		folha = 0;
		if(catmandu[s]) dfs(x, cats + catmandu[s], pop);
		else dfs(x, 0, pop);
	}
	if(folha){
		gatinhos++;
	}
}

int main(){
	rvr(n); rvr(m);
	frr(i, n) scanf("%d", &catmandu[i]);
	fr(i, n - 1){
		rvr(aux1); rvr(aux2);
		adj[aux1].pb(aux2);
		adj[aux2].pb(aux1);
	}
	dfs(1, 0, m);
	printf("%d\n", gatinhos);
}
