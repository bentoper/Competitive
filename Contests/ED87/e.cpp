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
const int N = 5e3 + 1;

int n, m, sz[3], compsz[N], vis[N], color[N], memo[N][N], ans[N][N];

vi adj[N];

vi comp[N];

int cur = 0, cursize = 0;

bool deu = true;

int dp(int i, int left){
    if(i == cur && left == 0) return 1;
    if(i == cur) return 0;
    if(memo[i][left] != -1) return memo[i][left];
    int& pdm = memo[i][left];
    pdm = 0;
    if(left >= compsz[i]){
        pdm |= dp(i+1, left - compsz[i]); 
    }
    if(pdm){
        ans[i][left] = 1;
        return pdm;
    }
    if(left >= comp[i].size() - compsz[i]) pdm |=  dp(i+1, left - comp[i].size() + compsz[i]);
    if(pdm) ans[i][left] = 0;
    return pdm;
}

void dfs(int v, int cor){
    color[v] = cor;
    comp[cur].pb(v);
    if(cor) cursize++;
    for(auto u: adj[v]){
        if(color[u] != -1 && !(color[v] ^ color[u])){
            deu = false;
            continue;
        } 
        if(color[u] != -1) continue;
        dfs(u, 1^cor);
    }
}

int main(){
    ms(color, -1);
    ms(memo, -1);
    scanf("%d%d", &n, &m);
    fr(i, 3) scanf("%d", &sz[i]);
    fr(i, m){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    frr(i, n){
        if(color[i] == -1){
            deu = true;
            cursize = 0;
            dfs(i, 0);
            if(!deu){
                printf("NO\n");
                return 0;
            }
            compsz[cur++] = cursize;
        }
    }
    if(dp(0, sz[1])){
        printf("YES\n");
        int sm = sz[1];
        fr(i, cur){
            for(auto v: comp[i]){
                if(color[v] == ans[i][sm]) color[v] = 2;
                else if(sz[0]){
                    color[v] = 1;
                    sz[0]--;
                }
                else color[v] = 3;
            }
            if(ans[i][sm]){
                sm -= compsz[i];
            }
            else sm -= (comp[i].size() - compsz[i]);
        }
        frr(i, n) printf("%d", color[i]);
        printf("\n");
    }
    else printf("NO\n");
}
