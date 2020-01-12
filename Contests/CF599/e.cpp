#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MAX = 80000;
const int N = 1<<16;

int k, n[16], memo[N];
vll seq[16];
ll bsum[16];

vi adj[MAX], cycle[N];

bool cover[N];
int id[MAX], vis[MAX], pro[MAX], ans[N], p[MAX], val[MAX];

pair<ll, int> perm[16];

map<ll, int> M; 


void dfs(int r, int par){
    p[r] = par;
    vis[r] = 1;
    pro[r] = 1;
    for(auto v: adj[r]){
        if(pro[v]){
            int w = r;
            int mask = 0;
            bool deu = true;
            vi plc;
            while(w != v){
                if(mask&(1<<id[w])){
                    deu = false;
                    break;
                }
                mask |= 1<<id[w];
                plc.pb(w);
                w = p[w];
            }
            if(!deu || mask&(1<<id[v])) continue;
            mask |= 1<<id[v];
            for(auto z: plc) cycle[mask].pb(z);
            cycle[mask].pb(v);
            cover[mask] = true;
            continue;
        }
        if(vis[v]) continue;
        dfs(v, r);
    }
    pro[r] = 0;
}

int dp(int mask){
    if(mask == 0) return 1;
    if(memo[mask] != -1) return memo[mask];
    if(cover[mask]) return memo[mask] = 1;
    memo[mask] = 0;
    for(int s = mask; s; s = (s-1)&mask){
        if(dp(s)&dp(mask^s)){
            ans[mask] = s;
            memo[mask] = 1;
            break;
        }
    }
    return memo[mask];
}

void recover(int mask){
    if(mask == 0) return;
    if(cycle[mask].empty()){
        recover(ans[mask]);
        recover(mask^ans[mask]);
        return;
    }
    int sz = cycle[mask].size();
    fr(i, sz){
        int pos = cycle[mask][i];
        int idd = id[pos];
        ll vv = seq[idd][val[pos]];
        perm[idd] = mp(vv, 1 + id[cycle[mask][(i + 1)%sz]]);
    }
    return;
}

int main(){
    ms(memo, -1);
    ms(ans, -1);
    ll sm = 0;
    scanf("%d", &k);
    int vertices = 0;
    fr(i, k){
        scanf("%d", &n[i]);
        fr(j, n[i]){
            ll a; scanf("%lld\n", &a); 
            seq[i].pb(a);
            bsum[i] += a;
            M[a] = ++vertices;
            id[vertices] = i;
            val[vertices] = j;
        }
        sm += bsum[i];
    }
    ll plcsum = (ll)k;
    ll diff = sm/(ll)k;
    if(plcsum*diff != sm){
        printf("No\n");
        return 0;
    }
    fr(i, k){
        fr(j, n[i]){
            int v = M[seq[i][j]];
            int u = M[diff - bsum[i] + seq[i][j]]; 
            if(u == 0 || (id[u] == id[v] && v != u)){
                continue;
            }
            adj[v].pb(u);
        }
    }
    frr(i, vertices){
        if(!vis[i]){
            dfs(i, i);
        }
    }
    int mask = 0;
    fr(i, k){
        mask |= 1<<i;
    }
    if(dp(mask)){
        printf("Yes\n");
        recover(mask);
        fr(i, k){
            printf("%lld %d\n", perm[i].first, perm[i].second);
        }
    }
    else printf("No\n");

}