//https://open.kattis.com/problems/numbersetshard
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
const int N = 1e6 + 1;
const int MAX_SIEVE = 1e6 + 2;


int main(){
    ll a = 0, b = 0;
    vll mid;
    int n; scanf("%d", &n);
    fr(i, n){
        int s; scanf("%d", &s);
        fr(j, s/2){
            ll plc; scanf("%lld", &plc);
            a += plc;
        }
        if(s%2){
            ll plc; scanf("%lld", &plc);
            mid.pb(plc);
        }
        fr(j, s/2){
            ll plc; scanf("%lld", &plc);
            b += plc;
        }
    }
    sort(all(mid));
    for(int i = mid.size() - 1, j = 0; i >= 0; i--, j++){
        if(j%2) b += mid[i];
        else a += mid[i];
    }
    printf("%lld %lld\n", a, b);
}