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
const int MAX_SIEVE = 1e6 + 1;

vector<int> prim;
int mark[MAX_SIEVE], lp[MAX_SIEVE], vec[MAX_SIEVE];

vi adj[MAX_SIEVE];
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), lp[i] = i;
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
            lp[i*p] = p;
			if(i%p == 0) break;
		}
	}
}

int sz[MAX_SIEVE];

int dfs(int r){
    sz[r] = 1;
    for(auto v: adj[r]){
        sz[r] += dfs(v);
    }

    return sz[r];
}


int main(){
    crivo();
    rvr(t);
    while(t--){
        ms(vec, 0);
        int n, m; scanf("%d%d", &n, &m);
        frr(i, n) adj[i].clear();
        frr(i, n-1){
            rvr(p);
            adj[p].pb(i+1);
        }
        frr(i, n-1){
            int x = i;
            while(x != 1){
                vec[lp[x]]++;
                x /= lp[x];
            }
        }
        dfs(1);
        frr(i, n-1){
            int x = sz[i+1];
            while(x != 1){
                vec[lp[x]]--;
                x /= lp[x];
            }
        }
        ll ans = 1;
        frr(i, n-1){
            if(vec[i] != 0){
                fr(j, vec[i]){
                    ans *= i;
                    ans %= m;
                }
            }
        }
        printf("%lld\n", ans);
    }
    
}
