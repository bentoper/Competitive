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
const int N = 2e5 + 1;

vi adj[N];

vi p;

int dist[N][3], par[N];

int main(){
    rvr(t);
    while(t--){
        rvr(n); rvr(m); rvr(A); rvr(B); rvr(C);
        p.clear();
        frr(i, n){
            adj[i].clear();
            fr(j, 3) dist[i][j] = -1;
        }
        fr(i, m){
            rvr(pp); p.pb(pp);
        }
        fr(i, m){
            rvr(a);
            rvr(b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int path = 0;
        dist[A][0] = 0;
        queue<int> q;
        q.push(A);
        par[A] = A;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u: adj[v]){
                if(dist[u][0] == -1){
                    dist[u][0] = dist[v][0] + 1;
                    par[u] = v;
                    q.push(u);
                }
            }
        } 
        while(!q.empty()) q.pop();
        dist[B][1] = 0;
        q.push(B);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u: adj[v]){
                if(dist[u][1] == -1){
                    dist[u][1] = dist[v][1] + 1;
                    q.push(u);
                }
            }
        }
        dist[C][2] = 0;
        q.push(C);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u: adj[v]){
                if(dist[u][2] == -1){
                    dist[u][2] = dist[v][2] + 1;
                    q.push(u);
                }
            }
        } 
        sort(all(p));
        vll pref;
        pref.pb(p[0]);
        frr(i, m-1){
            pref.pb(pref[i-1] + (ll)p[i]);
        }
        ll ans = llINF;
        frr(i, n){
            int tot = dist[i][1] + dist[i][0] + dist[i][2];
            if(tot > m) continue;
            tot--;
            ans = min(tot==-1?0:pref[tot]+((dist[i][1]==0)?0:pref[dist[i][1] - 1]), ans);
        }
        printf("%lld\n", ans);
    }
}
