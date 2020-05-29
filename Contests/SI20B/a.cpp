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
const int N = 2e3 + 1;

vi adj[N];
int dist[N][N], ans[N];

int main(){
    ms(dist, -1);
    rvr(n);
    int x, y; scanf("%d%d", &x, &y);
    adj[x].pb(y);
    adj[y].pb(x);
    frr(i, n-1){
        adj[i].pb(i+1);
        adj[i+1].pb(i);
    }
    queue<int> q;
    frr(i, n){
        dist[i][i] = 0;
        q.push(i);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u: adj[v]){
                if(dist[u][i] == -1){
                    dist[u][i] = dist[v][i] + 1;
                    q.push(u);
                    ans[dist[u][i]]++;
                }
            }
        }
    }
    frr(i, n-1){
        printf("%d\n", ans[i]/2);
    }
}
