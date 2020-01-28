//https://www.codechef.com/NOV15/problems/SMPLSUM
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
const int MAX_SIEVE = 1e7 + 1;

vector<ll> prim;
vector<bool> mark(MAX_SIEVE, false);

ll lp[MAX_SIEVE], lpcount[MAX_SIEVE];
ll ans[MAX_SIEVE];

	
void crivo(){
    ans[1] = 1;
	for(ll i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), ans[i] = i*i - i  + 1ll, lp[i] = i, lpcount[i] = i;
        for(ll p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = true;
			if(i%p == 0) {
			    lp[i*p] = p;
                lpcount[i*p] = lpcount[i]*p;
                if(lpcount[i*p] == i*p) ans[i*p] = ans[i] + (i*p)*(i*p - i);
                else ans[i*p] = (ans[i]/ans[lpcount[i]])*ans[lpcount[i*p]];
                break;
            }
            lp[i*p] = min(lp[i], p);
            if(lp[i*p] == p) lpcount[i*p] = p;
            ans[i*p] = ans[i]*ans[p];
		}
	}
}

ll solve(ll x){
    return ans[x];
}

int main(){
    crivo();
    int T; scanf("%d", &T);
    while(T--){
        ll n; scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }
}
