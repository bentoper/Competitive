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
#define f first
#define s second



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
const int N = 1e6 + 1;
const int mod = 1e9 + 7;

int par[N], depth[N];

vii edges[N];


int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;

}

bool check_cycle(vii& vec){
    if(vec[0].f == vec[1].f){
        if(vec[1].s == vec[2].f){
            return (vec[2].s == vec[0].s);
        }
        else if(vec[1].s == vec[2].s){
            return (vec[2].f == vec[0].s);
        }
        return false;
    }
    else if(vec[0].f == vec[1].s){
        if(vec[1].f == vec[2].f){
            return (vec[2].s == vec[0].s);
        }
        else if(vec[1].f == vec[2].s){
            return (vec[2].f == vec[0].s);
        }
        return false;
    }
    else if(vec[0].s == vec[1].f){
        if(vec[1].s == vec[2].f){
            return (vec[2].s == vec[0].f);
        }
        else if(vec[1].s == vec[2].s){
            return (vec[2].f == vec[0].f);
        }
        return false;
    }
    else if(vec[0].s == vec[1].s){
        if(vec[1].f == vec[2].f){
            return (vec[2].s == vec[0].f);
        }
        else if(vec[1].f == vec[2].s){
            return (vec[2].f == vec[0].f);
        }
        return false;
    }
    return false;
}

int main(){
    rvr(n);
    rvr(m);
    int mxc = -1;
    fr(i, m){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[c].pb({a, b});
        mxc = max(mxc, c);
    }
    frr(i, n){
        par[i] = i;
    }
    ll ans = 1;
    ll sz = 0;
    vii cur;
    int qnt = 0;
    frr(i, mxc){
        if(edges[i].size() == 0) continue;
        int dup = 0;
        cur.clear();
        for(auto p: edges[i]){
            if(find(p.first) == find(p.second)) continue;
            pii plc = mp(max(find(p.first), find(p.second)), min(find(p.first), find(p.second)));
            bool deu = true;
            for(auto q: cur){
                if(q == plc) deu = false;
            }
            if(deu) cur.pb(plc);
            else dup++;
        }
        if(cur.size() == 0) continue;
        /*printf("i %d dup %d\n", i, dup);
        for(auto p: cur){
            printf("%d %d\n", p.first, p.second);
        }*/
        if(dup >= 1){
            ans *= (ll)(dup+1);
        }
        else if(cur.size() == 3){
            if(check_cycle(cur)) ans *= 3ll, sz -= (ll)i, qnt--;
        }
        for(auto p: cur){
            join(p.first, p.second);
            sz += (ll)i;
            qnt++;
        }
        ans %= mod;
        //printf("%lld %lld %d\n", sz, ans, qnt);
    }
    printf("%lld %lld\n", sz, ans);
}
