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
const int N = 1e5 + 1;

int a[N], idx[N], b[N];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n, m; scanf("%d%d", &n, &m);
        fr(i, n){
            scanf("%d", &a[i]);
            idx[a[i]] = i;
        }
        fr(i, m) scanf("%d", &b[i]);
        ll ans = 0;
        int id = 0;
        fr(i, m){
            if(i == 0){
                ans = 2*idx[b[i]] + 1;
                id = idx[b[i]];
            }
            else{
                if(idx[b[i]] > id) ans += (ll)(2*(idx[b[i]] - i)) + 1ll;
                else ans++;
                id = max(idx[b[i]], id);
            }
        }
        printf("%lld\n", ans);
    }
}
