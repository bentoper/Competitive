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
const int N = 1e7 + 1;
const ll mult = 10000;

ll inv[N];

int main(){
    ll n;
    int pp, rr; 
    scanf("%lld%d%d", &n, &pp, &rr);
    ll p = pp, r = rr;
    ll tlefdp = mult*p;
    if(p == 2){
        if(n > 2 && r == 0){
            printf("3 1\n");
            return 0;
        }
        else if(n <= 2 && r == 0){
            printf("-1 -1\n");
            return 0;
        }
        if(n <= 3 && r == 1){
            printf("2 1\n");
            return 0;
        }
        printf("-1 -1\n");
        return 0;
    }
    if(n >= p && r == 0){
        printf("2 1\n");
        return 0;
    } 
    else if(n >= 2ll*p || (n < p && r == 0)){
        printf("-1 -1\n");
        return 0;
    }
    inv[1] = 1;
    ll fat = 1, nn = n%p;
    for(int i = 2; i < p; ++i){
        inv[i] = (p - ((p/(ll)i) * inv[p%i] )%p);
        if(i <= nn){
            fat *= i;
            if(fat >= tlefdp) fat %= p;
        }
    }
    fat %= p;
    if(n >= p){
        fat *= p - 1ll;
        fat %= p;
        printf("%lld %lld\n", p, (inv[fat]*r)%p);
        return 0;
    }
    for(ll i = 2; i <= n; i++){
        fat = (fat*inv[i])%p;
        ll plc = (inv[fat]*r)%p;    
        if(plc < i){
            printf("%lld %lld\n", i, plc);
            return 0;
        }
        fat = (fat*i)%p;
    }
    printf("-1 -1\n");

}
