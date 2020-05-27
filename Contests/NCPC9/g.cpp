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
const int N = 2501;

int a, b, vis[N], h[N], maxdist = -1, ver, par[N];

vi adj[N];

void dfs(int v){

    vis[v]  = 1;

    for(auto u: adj[v]){
        if(vis[u] || (a == v && b == u) || (a == u && b == v)) continue;
        par[u] = v;
        h[u] = h[v] + 1;
        dfs(u);
    }

    if(h[v] > maxdist){
        maxdist = h[v];
        ver = v;
    }
}

vii edg;

int main(){
    rvr(n);
    fr(i, n-1){
        int x, y; scanf("%d%d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
        edg.pb(mp(x, y));
    }
    int ans = INF, vaca1, vaca2;
    pii rm;
    pair<pii, pii> ad;
    fr(x, n-1){
        ms(vis, 0);
        maxdist = -1;
        h[1] = 0;
        a = edg[x].first, b = edg[x].second;
        dfs(1);
        int save1 = ver;
        ms(vis, 0);
        maxdist = -1;
        h[ver] = 0;
        dfs(ver);
        int save = maxdist, save2 = ver;
        maxdist = -1;
        frr(i, n){
            if(!vis[i]){
                h[i] = 0;
                dfs(i);
                ms(vis, 0);
                maxdist = -1;
                int save3 = ver;
                h[ver] = 0;
                dfs(ver);
                if(ans > max(((maxdist + 1)/2 + (save + 1)/2 + 1), max(maxdist, save))){
                    ans = max(((maxdist + 1)/2 + (save + 1)/2 + 1), max(maxdist, save));
                    rm = edg[x];
                    ad = mp(mp(save1, save2), mp(save3, ver));
                    vaca1 = save, vaca2 = maxdist;
                }
                break;
            }
        }
    }
    ms(vis, 0);
    h[ad.first.first] = 0, h[ad.second.first] = 0;
    a = rm.first, b = rm.second;
    dfs(ad.first.first);
    dfs(ad.second.first);
    printf("%d\n", ans);
    printf("%d %d\n", rm.first, rm.second);
    int vv = ad.first.second, uu = ad.second.second;
    while(h[vv] > vaca1/2) vv = par[vv];
    while(h[uu] > vaca2/2) uu = par[uu];
    printf("%d %d\n", vv, uu);
}
