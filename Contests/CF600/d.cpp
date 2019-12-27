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
const int N = 1e6 + 1;


// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[N], peso[N], grt[N];
int n, vis[N], m;
vi adj[N];


int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(peso[x] > peso[y]) swap(x, y);

	pai[x] = y;
	if(peso[x] == peso[y]) peso[y]++;
    grt[y] = max(grt[y], grt[x]);

}

void dfs(int r){
    vis[r] = 1;
    for(auto x: adj[r]){
        if(vis[x]) continue;
        join(r, x);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    frr(i, n){
        pai[i] = grt[i] = i;
        peso[i] = 1;
    }
    fr(i, m){
        int a, b; scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    frr(i, n){
        if(!vis[i]) dfs(i);
    }
    int ans = 0;
    frr(i, n-1){
        if(find(i) != find(i+1) && grt[find(i)] > i){
            join(i, i+1);
            ans++;
        }
    }
    printf("%d\n", ans);

}
