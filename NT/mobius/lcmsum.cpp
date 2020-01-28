//https://www.spoj.com/problems/GCDEX/
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
const int MAX_SIEVE = 1000002;

vector<ll> prim;
int mark[MAX_SIEVE];

ll phi[MAX_SIEVE];
	
void crivo(){
    phi[1] = 1;
	for(ll i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), phi[i] = i-1;
		for(ll p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) {
                phi[i*p] = phi[i]*p;
                break;
            }
            phi[i*p] = phi[i]*phi[p];
		}
	}
}

int main(){
    crivo();
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        ll ans = 0;
        for(ll i = 1; i*i <= n; i++){
            if(n%i == 0){
                ans += (phi[i]*i) + 1ll;
                if(n/i != i) ans += phi[n/i]*(n/i) + 1ll;
            }
        }
        ans /= 2ll;
        ans *= n;
        printf("%lld\n", ans);
    }
}
