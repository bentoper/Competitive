#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1]);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n, m, mid;
ll k, a[21][21], r = 0;

map<pair<pii, ll>, ll> ans;

void topdown(int x, int y, int mvs, ll xr){
    if(x >= n || y >= m) return;
    xr ^= a[x][y];
    if(mvs == mid){
        ans[mp(mp(x, y), xr)] += 1;
        return;
    }
    topdown(x+1, y, mvs+1, xr);
    topdown(x, y+1, mvs+1, xr);
}

void bottomup(int x, int y, int mvs, ll xr){
    if(x < 0 || y < 0) return;
    if(mvs == n + m - 2 - mid){
        if(ans[mp(mp(x, y), k^xr)]) r += ans[mp(mp(x, y), k^xr)]; 
        return;
    }
    xr ^= a[x][y];
    bottomup(x-1, y, mvs+1, xr);
    bottomup(x, y-1, mvs+1, xr);
}


int main(){
    scanf("%d%d%lld", &n, &m, &k);
    fr(i, n){
        fr(j, m){
            scanf("%lld", &a[i][j]);
        }
    }
    mid = (n+m-1)/2;
    topdown(0, 0, 0, 0);
    bottomup(n-1, m-1, 0, 0);
    printf("%lld\n", r);
}