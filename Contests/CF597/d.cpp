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
const int MAX = 2e3 + 1;

int par[MAX], depth[MAX], sz[MAX], mncost[MAX], loc[MAX];

map<int, pii> rid;
map<pii, int> id;

ll k[MAX];

struct edge{
    int x;
    int y;
    ll w;
};

vector<edge> edges;

int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;
	sz[y] += sz[x];
    if(mncost[y] > mncost[x]){
        loc[y] = loc[x];
        mncost[y] = mncost[x];
    }
}

bool mycomp(edge a, edge b){
    return a.w < b.w;
}

int main(){
    int n; scanf("%d", &n);
    vii ans;
    vi av;
    int comp = n;
    ll cost = 0;
    vii coiso;
    coiso.pb({0, 0});
    frr(i, n){
        int a, b; scanf("%d%d", &a, &b);
        coiso.pb(mp(a, b));
    }
    frr(i, n) scanf("%d", &mncost[i]);
    frr(i, n){
        int a = coiso[i].first, b = coiso[i].second;
        par[i] = i;
        loc[i] = i;
        scanf("%lld", &k[i]);
        int plc = id[mp(a, b)];
        if(plc != 0){
            ll C = mncost[plc] + mncost[i];
            cost += mncost[i];
            join(plc, i);
            ans.pb(mp(plc, i));
            C -= mncost[find(i)];
            cost -= C;
            comp--;
        }
        else av.pb(i), plc = i, rid[i] = mp(a, b), cost += (ll)mncost[i];
    }
    for(auto v: av){
        for(auto u: av){
            if(v == u) continue;
            edges.pb({v, u, (k[u] + k[v])*((ll)abs(rid[v].first - rid[u].first) + (ll)abs(rid[v].second - rid[u].second))});
        }
    }
    sort(all(edges), mycomp);
    for(auto e: edges){
        int u = e.y, v = e.x;
        ll w = e.w;
        if(find(u) == find(v)) continue;
        if((ll)mncost[find(u)] + (ll)mncost[find(v)] > (ll)min(mncost[find(u)], mncost[find(v)]) + w){
            cost -= (ll)max(mncost[find(u)], mncost[find(v)]);
            cost += w;
            join(u, v);
            comp--;
            ans.pb({u, v});
        }
    }
    printf("%lld\n%d\n", cost, comp);
    set<int> locations;
    frr(i, n){
        if(locations.count(loc[find(i)]) != 0) continue;
        locations.insert(loc[find(i)]);
        printf("%d ", loc[find(i)]);
    }
    printf("\n%d\n",(int)ans.size());
    for(auto p: ans){
        printf("%d %d\n", p.first, p.second);
    }
}
