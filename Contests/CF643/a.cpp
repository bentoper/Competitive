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

ll solve(ll a, ll k){
    if(k == 0) return a;
    int mx = -1, mn = 10;
    ll base = 10;
    ll acp = a;
    while(acp){
        mx = max(mx, (int) (acp%10));
        mn = min(mn, (int)(acp%10));
        acp /= 10ll;
    }
    if(mx == 0 || mn == 0) return a;
    return solve(a + (ll)(mn*mx), k - 1);
}

int main(){
    rvr(t);
    while(t--){
        ll a, k; scanf("%lld%lld", &a, &k);
        int mn = 10, mx = -1;
        ll base = 10;
        printf("%lld\n", solve(a, k-1));
    }

}
