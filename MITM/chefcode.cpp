//https://www.codechef.com/MAY17/problems/CHEFCODE/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%lld%c", x[i], " \n"[i==n-1])

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl printf("\n");
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef stack<int> SI;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;
ll a[40], k, ans;
vector<long long int> l;

int main(){
    scanf("%d%lld", &n, &k);
    fr(i, n) scanf("%lld", &a[i]);
    int mid = n>>1;
    int left = n - mid;
    for(int i = 1; i < 1<<mid; i++){
        ll plc = 1;
        fr(j, mid){
            if(i&(1<<j)){
                if(a[j] > (ll)(k/plc)){
                    plc = -1;
                    break;
                }
                plc *= a[j];
            }
        }
        if(plc != -1){
            ans++;
            l.pb(plc);
        }
    }
    sort(all(l));
    for(int i = 1; i < 1<<left; i++){
        ll plc = 1;
        fr(j, left){
            if(i&(1<<j)){
                if(a[j + mid] > (ll)(k/plc)){
                    plc = -1;
                    break;
                }
                plc *= a[j+mid];
            }
        }
        if(plc != -1){
            ans++;
            ll vaca = k/plc;
            ans += upper_bound(all(l), vaca) - l.begin();
        }
    }
    printf("%lld\n", ans);
}