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
#define MAXN 1

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


int clk = 0;

int low[MAXN], pre[MAXN], qnt;

stack<int> eds;

bool art[MAXN], used[2*MAXN];

struct Edges{
	int x, y, id;
};

vi bridges, comps[MAXN];

vector<Edges> edges[MAXN];

void makecomp(int id){
	while(eds.top() != id){
		comps[qnt].pb(eds.top());
		eds.pop();
	}
	if(id != -1) comps[qnt++].pb(id);
	eds.pop();
}


int dfs(int v, int p, int id){
	

	if(id == -1 || !used[id]){
		eds.push(id);
		used[id] = true;
	}

	pre[v] = clk++;
	low[v] = pre[v];
	bool forw = false;
	for(auto e: edges[v]){
		int x = e.y;
		if(e.id == id) continue;
		if(pre[x] == -1){
			dfs(x, v, e.id);
			low[v] = min(low[v], low[x]);
			if(pre[x] == low[x]){
				bridges.pb(e.id);
			}
			if(v != p ? low[x] >= pre[v] : forw){
				art[v] = true;
				makecomp(e.id);
			}
			forw = true;
		}
		else low[v] = min(low[v], pre[x]);
	}
}

int main(){

}
