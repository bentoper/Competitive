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
#define f first
#define s second


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 1e4 + 1;


int vis[N], n, m;

vi adj[N];

pii edg[N];

int cyc[N], stp[N], seen[N], odcyc[N], h[N], odstp[N];

int cyctot = 0;

int TOD = 0;

pii dfs(int v, int p){
    h[v] = h[p] + 1;
    int cur = 0, odcur = 0;
    for(auto i: adj[v]){
        if(seen[i]) continue;
        seen[i] = 1;
        int u = edg[i].f + edg[i].s - v;
        if(h[u] > 0 && u != p){
            stp[u]++;
            if((h[v] - h[u] + 1)%2) odstp[u]++, odcur++, odcyc[i]++, TOD++;
            cyc[i]++;
            cur++;
            continue;
        }
        if(u == p) continue;
        pii plc = dfs(u, v);
        cyc[i] += (plc.f - stp[u]);
        odcyc[i] += (plc.s - odstp[u]);
        cur += (cyc[i]);
        odcur += odcyc[i];
    }
    return mp(cur, odcur);
}


int main(){
    scanf("%d%d", &n ,&m);
    fr(i, m){
        scanf("%d%d", &edg[i].f, &edg[i].s);
        adj[edg[i].f].pb(i);
        adj[edg[i].s].pb(i);
    }
    fr(i, n){

        if(!h[i]) dfs(i, i);
    }
    int ans = 0;
    fr(i, m){
        ans += (odcyc[i] == TOD && (odcyc[i] == cyc[i] || TOD == 0));    
    }
    printf("%d\n", ans);
    fr(i, m){
        if(odcyc[i] != TOD || (TOD && odcyc[i] != cyc[i])) continue; 
        printf("%d", i+1);
        printf(" ");
    }
    printf("\n");
}
