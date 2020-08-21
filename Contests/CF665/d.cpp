#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tcase(t) rvr(t); while(t--)


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
const ll MOD = 1e9 + 7;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 1e5 + 1;

int sz[N], n;
vi adj[N];
vll bld;

int dfs(int v){
    sz[v] = 1;
    for(auto u: adj[v]){
        if(sz[u]) continue;
        sz[v] += dfs(u);
    }
    if(v != 1) bld.pb((ll)(sz[v])*(ll)(n - sz[v]));
    return sz[v];
}

int main(){
    tcase(t){
        scanf("%d", &n);
        bld.clear();
        frr(i, n){
            adj[i].clear();
            sz[i] = 0;
        }
        fr(i, n-1){
            int x, y; scanf("%d%d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(1);
        sort(all(bld));
        rvr(m);
        vi prim(m);
        fr(i, m) scanf("%d", &prim[i]);
        sort(all(prim));
        int i = n - 2, j = m - 1;
        ll ans = 0;
        ll plc = 1;
        while(j > i){
            plc *= (ll)prim[j];
            plc %= MOD;
            j--;
        }
        while(j > -1){
            plc *= (ll)prim[j];
            plc %= MOD;
            ans += bld[i]*plc;
            ans %= MOD;
            plc = 1;
            i--;
            j--;
        }
        while(i > -1){
            ans += bld[i--];
            ans %= MOD;
        }
        printf("%lld\n", ans);

    }
}
