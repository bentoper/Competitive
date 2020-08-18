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

int main(){
    int n;
    scanf("%d", &n);
    vi f(n), c(n), l(n);
    ll sm  = 0;
    int mx = 0;
    fr(i, n) scanf("%d", &f[i]);
    fr(i, n) scanf("%d", &c[i]);
    fr(i, n) scanf("%d", &l[i]);
    fr(i, n){
        mx--;
        mx = max(mx, f[i]);
        if(mx < l[i] && i == n-1){
            printf("Impossible\n");
            return 0;
        }
        if(mx >= l[i]) sm = max(sm, (ll)mx*(ll)c[i]);
    }
    printf("%lld\n", sm);
}
