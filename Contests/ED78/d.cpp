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

int n, l[N], r[N], vis[N/2 + 1], ed[N/2 + 1];
vi adj[N/2 + 1];
set<pii> curr;


void dfs(int r, int p){
    vis[r] = 1;
    for(auto x: adj[r]){
        if(vis[x]) continue;
        dfs(x, r);
    }
}

int mxend = -1;

vi pos;

int main(){
    scanf("%d", &n);
    frr(i, n){
        int a, b;
        scanf("%d%d", &a, &b);
        mxend = max(mxend, b);
        l[a] = i;
        r[b] = i;
        ed[i] = b;
    }
    int ar = 0;
    for(int i = 1; i <= mxend; i++){
        if(l[i] != 0){
            for(auto z: curr){
                int x = z.first;
                int v =z.second;
                if(ed[l[i]] > x){
                    adj[l[i]].pb(v);
                    adj[v].pb(l[i]);
                    ar++;
                }
                else break;
                if(ar >= n){
                    printf("NO\n");
                    return 0;
                }
            }
            curr.insert(mp(ed[l[i]], l[i]));
        }
        if(r[i] != 0){
            curr.erase(mp(i, r[i]));
        }
    }
    if(ar != n-1){
        printf("NO\n");
        return 0;
    }
    dfs(1, 1);
    frr(i, n){
        if(vis[i] == 0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
