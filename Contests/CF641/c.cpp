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
int mark[MAX_SIEVE], lp[MAX_SIEVE], lpow[MAX_SIEVE];
int id[MAX_SIEVE], powers[MAX_SIEVE];
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), lp[i] = i, lpow[i] = i;
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
            lp[i*p] = p;
            if(lp[i] == p) lpow[i*p] = lpow[i]*p;
            else lpow[i*p] = p;
			if(i%p == 0) break;
		}
	}
}

int main(){
    crivo();
    fr(i, prim.size()){
        id[prim[i]] = i; 
    }
    rvr(n);
    fr(i, n){
        rvr(aa);
        while(aa != 1){
            powers[lpow[aa]]++;
            aa = aa/lpow[aa]; 
        }
    }
    ll ans = 1;
    for(auto p: prim){
        ll plc = p;
        while(plc*(ll)p <= 1000000) plc *= (ll)p;
        bool deu = false;
        while(plc > p){
            if(powers[plc] >= n-1){
                ans *= (ll)plc;
                deu = true;
                break;
            }
            powers[plc/p] += powers[plc];
            plc /= p;
        }
        if(!deu && powers[p] >= n-1) ans *= (ll)p;
    }
    printf("%lld\n", ans);
}
