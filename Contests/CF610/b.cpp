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

int g[212345];

int main(){
    int t; cin >> t;
    while(t--){
        int n, p, k; cin >> n >> p >> k;
        fr(i, n){
            cin >> g[i];
        }
        sort(g, g+n);
        int pp = p, i = 0, ans = 0, cur = 0;
        while(i < n){
            if(g[i] <= pp){
                if(i == 0) cur += 1;
                else cur += 2;
                ans = max(ans, cur);
                pp -= g[i];
                i += 2;
            }
            else break;
        }
        if(i <= n && i > 0 && pp >= g[i-1]) ans = max(ans, cur + 1);
        i = 1, cur = 0;
        while(i < n){
            if(g[i] > p) break;
            cur += 2;
            p -= g[i];
            ans = max(ans, cur);
            i += 2;
        }
        if(i <= n && i > 0 && p >= g[i-1]) ans = max(ans, cur + 1);
        cout << ans << endl;
    }
}
