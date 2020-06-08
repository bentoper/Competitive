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
    vi py;
    ll h = 1;
    ll plc = 2;
    while(plc <= 1e9){
        py.pb(plc);
        h++;
        plc = ((h + 1ll)*h) + (h*(h-1ll))/2ll; 
    }
    rvr(t);
    int tam = py.size();
    while(t--){
        rvr(n);
        int ans = 0;
        while(1){
            int pos = lower_bound(all(py), n) - py.begin();
            if(pos == tam || py[pos] > n) pos--;
            if(pos == -1 || py[pos] > n) break;
            ans++;
            n -= py[pos];
        }
        printf("%d\n", ans);
    }
}
