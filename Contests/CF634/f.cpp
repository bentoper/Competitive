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
const int N = 1e6 + 1;

string grid[N], dir[N];


int pre[N], dist[N], pro[N], par[N], incycle[N], br[N], id[N];

int clk = 0, cid = 1, n, m;

vector<vi> comp;

int nd(int i, int j){
    return i*m + j;
}

void dfs(int i, int j){
    pro[nd(i, j)] = 1;
    pre[nd(i, j)] = clk++;
    char d = dir[i][j];
    int ni = i , nj = j; 
    if(d == 'U'){
        ni--;
    }
    else if(d == 'D') ni++;
    else if(d == 'L') nj--;
    else nj++;
    if(pre[nd(ni, nj)] == -1){
        par[nd(ni, nj)] = nd(i, j);
        dfs(ni, nj);
    }
    else if(pro[nd(ni, nj)]){
        int v = nd(i, j);
        while(v != nd(ni, nj)){
            incycle[v] = cid;
            br[cid] += (grid[v/m][v%m] == '1');
            v = par[v];
        }
        incycle[v] = 1;
        br[cid] += (grid[v/m][v%m] == '1');
        cid++;
    }
    if(!incycle[nd(i, j)]) dist[nd(i, j)] = dist[nd(ni, nj)] + 1;
    else{
        if(incycle[nd(ni, nj)]) id[nd(i, j)] = incycle[nd(ni, nj)];
        else id[nd(i, j)] = id[nd(ni, nj)];
    }
    pro[nd(i, j)] = 0;
}

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        cid = 1;
        clk = 0;
        cin >> n >> m;
        fr(i, n){
            cin >> grid[i];
        }
        fr(i, n) cin >> dir[i];
        fr(i, n*m){
            pre[i] = 0;
            incycle[i] = 0;
            dist[i] = 0;
            br[i];
        }
        fr(i, n){
            fr(j, m){
                if(pre[nd(i, j)] == -1) dfs(i, j);
            }
        }
        comp.clear();
        comp.resize(cid-1);
        fr(i, n*m){
            if(grid[i/m][i%m] == '1'){
                if(incycle[i]) comp[incycle[i]-1].pb(i);
            }
        }
    }
}
