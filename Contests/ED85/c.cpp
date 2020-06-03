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
const ll llINF = 1e18;
const int N = 3e5 + 1;

pll a[N];

int main(){
    rvr(t);
    while(t--){
        rvr(n);
        fr(i, n){
            scanf("%lld%lld", &a[i].first, &a[i].second);
        }
        int i = 0, j = 0;
        ll ans = 0, otp = llINF;
        while(i != n){
            if(!i){
                ans += a[i].first;
                for(j = i+1; j<= n-1; j++){
                    if(a[j-1].second - a[j].first >= 0) continue;
                    else ans += -a[j-1].second + a[j].first;
                }
                j--;
            }
            else{
                ans -= a[i - 1].first;
                ans += min(a[i-1].second, a[i].first);
                int lastj = ((j-1)<0)?(n-1):(j-1);
                ans += max(a[j].first - a[lastj].second, 0ll);
            }
            otp = min(otp, ans);
            i++;
            j = (j+1 == n)?0:(j+1); 
        }
        printf("%lld\n", otp);
    }
}
