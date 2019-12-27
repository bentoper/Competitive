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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 2e2 + 10;

int n, k, a[N];
ll memo[N][N];
vi adj[N];

void dp(int r, int p){
    memo[r][0] = a[r];
    for(auto v: adj[r]){
        if(v != p) dp(v, r);
    }
    fr(i, n){
        if(i == 0){
            for(auto v: adj[r]){
                if(v == p) continue;
                memo[r][0] += memo[v][k-1];
            }
        }
        else{
            for(auto v: adj[r]){
                if(v == p) continue;
                ll plc = 0;
                for(auto u: adj[r]){
                    if(u == v || u == p) continue;
                    plc += memo[u][max(i - 1, k - i - 1)];
                }
                memo[r][i] = max(memo[r][i], plc + memo[v][i-1]);
            }
        }
    }
    fr(i, n-1) memo[r][n-2-i] = max(memo[r][n-2-i], memo[r][n-i-1]);

}

int main(){
    scanf("%d%d", &n, &k);
    frr(i, n) scanf("%d", &a[i]);
    fr(i, n-1){
        rvr(u); rvr(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    k++;
    dp(1, -1);
    printf("%lld\n", memo[1][0]);
}
