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
const int N = 3e5 + 1;

ll memo[N][2];
int a[N], n;


ll dp(int i, int s){
    if(i == n) return 0;
    ll& pdm = memo[i][s];
    if(pdm != -1) return pdm;
    pdm = (s>0?-1ll:1ll)*(ll)a[i] + dp(i+1, 1^s);
    pdm = max(pdm, dp(i+1, s));
    pdm = max(pdm, 0ll);
    //mprintf("i %d s %d pdm %d\n", i, s, pdm);
    return pdm;
}

int main(){
    tsts(t){
        scanf("%d", &n);
        int q; scanf("%d", &q);
        fr(i, n){
            fr(j, 2) memo[i][j] = -1;
            scanf("%d", &a[i]);
        }
        printf("%lld\n", dp(0, 0));
    }
}
