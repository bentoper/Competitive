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

const int N = 1e5 + 1;

int a[16][N];

int main(){
    fastio;
    int n, clk = 0;
    while(cin >> n && n != -1){
        ll delta = 0, ans = 0;
        fr(i, n){
            cin >> a[15][i];
            fr(j, 15){
                a[j][i] = a[15][i]%(1<<(j+1));
            }
        }
        fr(j, 16) sort(a[j], a[j]+n);
        char c;
        while(cin >> c && c != 'E'){
            if(c == 'Q'){
                int k; cin >> k;
                int md = (1<<(k+1)), base = (1<<k);
                int rt = delta%md;
                if(rt < base){
                    ll low = lower_bound(a[k], a[k] + n, base - rt) - a[k];
                    ll up = lower_bound(a[k], a[k] + n, md - rt) - a[k];
                    ans += (up - low);
                }
                else if(rt > base){
                    ll low = lower_bound(a[k], a[k]+n, md - rt) - a[k];
                    ll up = lower_bound(a[k], a[k]+n, md - rt + base) - a[k];
                    ans += low;
                    ans += (n - up);
                }
                else ans += (ll)(lower_bound(a[k], a[k]+n, base) - a[k]);
            }
            else{
                ll plc; cin >> plc;
                delta += plc;
                delta %= (1<<16);
            }
        }
        cout << "Case " << ++clk << ": " << ans << endl;
    }
}
