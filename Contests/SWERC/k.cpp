#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


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
const int MAXN = 100001;

vi adj[MAXN];
int clk = 1;

int low[MAXN], pre[MAXN], numSCC, id[MAXN], sp[MAXN], ngb[MAXN];

stack<int> eds, nodes;


void dfs(int v, int p){

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];
	for(auto x: adj[v]){
		if(pre[x] == -1){
			dfs(x, v);
			low[v] = min(low[v], low[x]);
		}
		else low[v] = min(low[v], low[x]);
	}

	if(low[v] == pre[v]){
		while(true){
			int j = nodes.top();
			nodes.pop();
			id[j] = numSCC;
			low[j] = MAXN;
            sp[numSCC] += ngb[j];
			if(j == v) break;
		}
		numSCC++;
	}

}

set<int> adjcomp[MAXN];

int vis[MAXN], deu[MAXN];

int cdfs(int v){
    vis[v] = 1;
    if(sp[v] >= 2) deu[v] = 1;
    for(auto u: adjcomp[v]){
        if(sp[u] > 0) deu[v] = 1;
        if(vis[u]) deu[v] |= deu[u];
        else{
            deu[v] |= cdfs(u);
        }
    }
    return deu[v];
}

int main(){
    int n, m, t; scanf("%d%d%d", &n, &m, &t);
    fr(i, m){
        int a, b; scanf("%d%d", &a, &b);
        adj[a].pb(b);
        if(b == t) ngb[a] = 1;
    }
    ms(pre, -1);
    pre[t] = 0, low[t] = MAXN, numSCC++, id[t] = 0; 
    fr(i, n){
        if(pre[i] == -1) dfs(i, i);
        //printf("pre[%d] = %d\n", i, pre[i]);
    }
    vi ans;
    fr(i, n){
        for(auto v: adj[i]){
            if(id[v] != id[i]) adjcomp[id[i]].insert(id[v]);
        }
    }
    vis[0] = 1, deu[0] = 0;
    fr(i, numSCC){
        if(!vis[i]) cdfs(i);
    }
    fr(i, n){
        if(ngb[i] && !deu[id[i]]) ans.pb(i);
    }
    int sz = ans.size();
    printf("%d\n", sz);
    fr(i, sz){
        printf("%d\n", ans[i]);
    }
}
