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
const int N = 2e5 + 1;

int a[N];
int pre[11];

vi M[11];

int dig(int x){
    int ans = 0;
    while(x > 0) ans++, x /= 10;
    return ans;
}

int main(){
    int k, n; scanf("%d%d", &n, &k);
    fr(i, n){
        scanf("%d", &a[i]);
        M[dig(a[i])].pb(a[i]%k);
    }
    frr(i, 10) sort(all(M[i]));
    ll ans = 0;
    pre[0] = 1;
    int plc;
    frr(i, 10) pre[i] = (10ll*(ll)pre[i-1])%k;
    fr(i, n){
        frr(j, 10){
            plc = (k-((ll)pre[j]*(ll)a[i])%k);
            if(plc == k) plc = 0;
            ans += (ll)(upper_bound(all(M[j]), plc) - lower_bound(all(M[j]), plc));
        }
        if((((ll)pre[dig(a[i])]*(ll)a[i])%k + (ll)(a[i]%k))%k == 0) ans--;
    }
    printf("%lld\n", ans);
}
