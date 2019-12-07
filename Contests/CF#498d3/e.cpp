#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1]);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 212345;


vi adj[N];
int pre[N], id[N], clk = 0, post[N], pid[N];
int n, q;

void dfs(int v){
    pre[clk++] = v;
    id[v] = clk-1;
    for(auto u: adj[v]){
        dfs(u);
    }
    post[clk-1] = v;
    pid[v] = clk;
}


int main(){
    scanf("%d%d", &n, &q);
    frr(i, n - 1){
        int a; scanf("%d", &a);
        adj[a].pb(i+1);
        sort(all(adj[a]));
    }
    dfs(1);
    //pv(id, n + 1);
    //pv(pid, n + 1);
    fr(i, q){
        int u, k; scanf("%d%d", &u, &k);
        //printf("%d %d %d\n", id[u], pid[u], k);
        if(pid[u] - id[u] < k) printf("-1\n");
        else printf("%d\n", pre[id[u] + k - 1]);
    }
}