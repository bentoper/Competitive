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
const int N = 202;
int r, g, b;
vi R, G, B;

ll memo[N][N][N];

ll dp(int i, int j, int k){
    if((i == r) + (j == g) + (k == b) > 1) return 0;
    ll& pdm = memo[i][j][k];
    if(pdm != -1) return pdm;
    pdm = 0;
    if(i != r){
        if(j != g){
            pdm = max(pdm, dp(i + 1, j+1, k) + (ll)(R[i]*G[j]));
        }
        if(k != b){
            pdm = max(pdm, dp(i + 1, j, k + 1) + (ll)(R[i]*B[k]));
        }
    }
    if(j != g && k != b){
        pdm = max(pdm, dp(i, j + 1, k + 1) + (ll)(G[j]*B[k]));
    }
    return pdm;

}

int main(){
    scanf("%d%d%d", &r, &g, &b);
    ll ans = 0;
    fr(i,r){
        rvr(a);
        R.pb(a);
    }
    fr(i,g){
        rvr(a);
        G.pb(a);
    }
    fr(i,b){
        rvr(a);
        B.pb(a);
    }
    fr(i, r+1){
        fr(j, g+1){
            fr(k, b+1) memo[i][j][k] = -1;
        }
    }
    sort(all(R));
    reverse(all(R));
    sort(all(G));
    reverse(all(G));
    sort(all(B));
    reverse(all(B));
    printf("%lld\n", dp(0, 0, 0));
}
