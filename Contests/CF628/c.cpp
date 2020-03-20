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
const int N = 1e5 + 1;

vi adj[N];

int deg[N];

int main(){
    rvr(n);
    vii edg;
    fr(i, n-1){
        rvr(a); rvr(b);
        edg.pb(mp(a, b));
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    frr(i, n) deg[i] = adj[i].size();
    frr(i, n) if(deg[i] == 1) q.push(i);
    map<pii, int> M;
    fr(i, n-1){
        int v = q.front(), u;
        deg[v] = 0;
        q.pop();
        for(auto x: adj[v]){
            if(deg[x]){
                u = x;
            }
            deg[x]--;
            if(deg[x] == 1) q.push(x);
        }
        M[mp(v, u)] = i+1;
        //printf("v %d u %d\n", v, u);
    }
    fr(i, n-1){
        int a = M[mp(edg[i].first, edg[i].second)];
        if(!a){
            swap(edg[i].first, edg[i].second);
            a = M[mp(edg[i].first, edg[i].second)];
        }
        printf("%d\n", a-1);
    }
}
