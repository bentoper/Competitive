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
const int N = 3e5 + 1;
const double eps = 1e-4;

int a[N];

double pref[N], mx[N];

int main(){
    int n, k; scanf("%d%d", &n, &k);
    int mxx = -1;
    fr(i, n){
        scanf("%d", &a[i]);
        mxx = max(mxx, a[i]);
    }
    if(k == 1){
        printf("%d\n", mxx);
        return 0;
    }
    double l = 1, r = 1e6;
    double ans = -1;
    while(r - l > eps){
        double mid = (l + r)/2.0;
        fr(i, n){
            if(i) pref[i] = pref[i - 1] - mid + (double)a[i], mx[i] = min(pref[i], mx[i-1]);
            else pref[i] = ((double)a[i]) - mid, mx[i] = pref[i];
        }
        bool deu = false;
        for(int i = n - 1; i >= k; i--){
            if(pref[i] - mx[i - k] > eps){
                deu = true;
                break;
            }
        }
        if(deu){
            ans = max(ans, mid);
            l = mid;
        }
        else r = mid;
    }
    printf("%.3lf\n", ans);
}
