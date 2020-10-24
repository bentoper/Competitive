#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)

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

struct nd{
    ll mx, diff, qnt;
};

vi adj[N];

ll arr[N];

nd dfs(int v){
    bool end = true;
    nd cur;
    cur.mx = -1, cur.diff = 0, cur.qnt = 0;
    for(auto u: adj[v]){
        end = false;
        if(cur.mx == -1){
            cur = dfs(u);
        }
        else{
            nd plc = dfs(u);
            cur.diff = max(cur.mx, plc.mx)*(cur.qnt + plc.qnt) - (cur.mx*cur.qnt - cur.diff) - (plc.mx*plc.qnt - plc.diff);
            cur.mx = max(cur.mx, plc.mx);
            cur.qnt += plc.qnt;
        }
    }
    if(end){
        cur.mx = arr[v];
        cur.qnt = 1;
    }
    else{
        if(cur.diff > 0){
            ll vaca = min(cur.diff, arr[v]);
            arr[v] -= vaca;
            cur.diff -= vaca;
            if(arr[v] > 0){
                cur.mx += arr[v]/cur.qnt + (arr[v]%cur.qnt > 0);
                if((arr[v]%cur.qnt > 0)){
                    cur.diff = cur.qnt - arr[v]%cur.qnt;
                }
            }
        }
        else{
            if((arr[v]%cur.qnt > 0)) cur.diff = cur.qnt - arr[v]%cur.qnt;
            cur.mx += arr[v]/cur.qnt + (arr[v]%cur.qnt > 0);
        }
    }
    return cur;
}

int main(){
    rvr(n);
    frr(i, n-1){
        rvr(a);
        adj[a-1].pb(i);
    }
    fr(i, n){
        scanf("%lld", &arr[i]);
    }
    printf("%lld\n", dfs(0).mx);
}
