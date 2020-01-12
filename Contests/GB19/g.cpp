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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

int a[N], vis[N], pro[N], par[N];

vi adj[N], cycle;

bool findcycle = false;

bool dfs(int v, int p){
    vis[v] = 1;
    pro[v] = 1;
    par[v] = p;
    for(auto u: adj[v]){
        if(pro[u]){
            findcycle = true;
            while(v != u){
                cycle.pb(v);
                v = par[v];
            }
            cycle.pb(v);
            return true;
        }
        if(vis[u]) continue;
        if(dfs(u, v)) return true;
    }
    pro[v] = 0;
    return false;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        frr(i, n){
            adj[i].clear();
            vis[i] = 0;
            pro[i] = 0;
        }
        cycle.clear();
        findcycle = false;
        frr(i, n){
            scanf("%d", &a[i]);
            adj[i].pb(i - a[i]);
        }
        for(int i = 1; i <= n && !findcycle; i++){
            if(!vis[i]) dfs(i, i);
        }
        printf("%d\n", (int)cycle.size());
        pv(cycle, cycle.size());
    }    
}
