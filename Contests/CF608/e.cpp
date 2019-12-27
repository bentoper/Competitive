#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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

ll n, k;

ll paths(ll x){
    ll ans = 0;
    ll l, r;
    if(x%2) l = 2*x, r = 2*x + 1ll, ans = 1ll;
    else l = x, r = x + 1ll;
    while(l <= n && r <= n){
        ans += r - l + 1ll;
        l *= 2ll;
        r *= 2ll;
        r+=1ll;
        //printf("ans %lld r %lld\n", ans, r);
    }
    if(l <= n) ans += n - l + 1ll;
    //printf("l %lld x %lld pths %lld\n", l, x, ans);
    return ans;
}


ll oddsolve(){
    ll r = n - (1-n%2);
    ll l = 1;
    ll ret = -1;
    while(l <= r){
        ll mid = (l+r)>>1ll;
        if((mid%2ll) == 0) mid++;
        //printf("%lld %lld\n", mid, paths(mid));
        if(paths(mid) < k){
            r = mid - 2;
        }
        else ret = max(ret, mid), l = mid + 2;
    }
    //printf("l %lld r %lld\n", l, r);
    return ret;
}

ll evensolve(){
    ll r = n - n%2;
    ll l = 2;
    ll ret = -1;
    while(l <= r){
        ll mid = (l+r)>>1ll;
        if(mid%2ll) mid++;
        //printf("%lld %lld\n", mid, paths(mid));
        if(paths(mid) < k){
            r = mid - 2;
        }
        else ret = max(ret, mid), l = mid + 2;
    }
    //printf("l %lld r %lld\n ret %lld", l, r, ret);
    return ret;
}


int main(){
    scanf("%lld%lld", &n, &k);

    if(k == n){
        printf("1\n");
        return 0;
    }
    if(k == 1){
        printf("%lld\n", n);
        return 0;
    }

    printf("%lld\n", max(oddsolve(), evensolve()));

}
