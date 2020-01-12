#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])


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
const int N = 2e3 + 10;

vi adj[N];
int dist[2][N], w[N][N];


void dijkstra(int v, int mode){
    set<pii> S;
    dist[mode][v] = 0;
    S.insert(mp(0, v));
    while(!S.empty()){
        int u = (*S.begin()).second;
        int d = (*S.begin()).first;
        S.erase(S.begin());
        for(auto x: adj[u]){
            if(dist[mode][x] > d + w[u][x]){
                if(dist[mode][x] != INF) S.erase(mp(dist[mode][x], x));
                dist[mode][x] = d + w[u][x];
                S.insert(mp(dist[mode][x], x));
            }
        }
    }
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n, m, t; scanf("%d%d%d", &n, &m, &t);
        int s, g, h; scanf("%d%d%d", &s, &g, &h);
        fr(i, n+1){
            fr(j, 2) dist[j][i] = INF;
            adj[i].clear();
        }
        fr(i, m){
            rvr(a); rvr(b); rvr(d);
            adj[a].pb(b);
            adj[b].pb(a);
            w[a][b] = d;
            w[b][a] = d;
        }
        vi dest;
        fr(i, t){
            rvr(a);
            dest.pb(a);
        }
        dijkstra(s, 0);
        //pvv(dist[0], n);
        int rr = h;
        if(dist[0][g] > dist[0][h]){
            rr = g;
        }
        dijkstra(rr, 1);
        vi ans;
        for(auto vertex: dest){
            if(dist[0][vertex] == dist[0][rr] + dist[1][vertex]) ans.pb(vertex);
        }
        sort(all(ans));
        pv(ans, ans.size());
    }
}
