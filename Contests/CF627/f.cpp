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
const int N = 2e5 + 1;

int a[N], dp[N], ans[N], par[N];
int vis[N];

vi adj[N];

void dfs(int v){
    vis[v] = 1;
    dp[v] = a[v];
    for(auto u: adj[v]){
        if(vis[u]) continue;
        par[u] = v;
        dfs(u);
        dp[v] += max(dp[u], 0);
    }
}

void calc(int v){
    ans[v] = dp[v];
    for(auto u: adj[v]){
        if(u != par[v]){
            dp[v] -= max(0, dp[u]);
            dp[u] += max(0, dp[v]);
            calc(u);
            dp[u] -= max(0, dp[v]);
            dp[v] += max(0, dp[u]);
        }
    }
}

int main(){
    rvr(n);
    frr(i, n) scanf("%d", &a[i]), dp[i] = -1, ans[i] = -1, a[i]=(a[i]==1)?1:-1;
    fr(i, n-1){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    par[1] = 1;
    dfs(1);
    calc(1);
    pvv(ans, n);
}
