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
const int N = 1e6 + 2;

int n, k, memo[N], pref[N], a[N];

int dp(int i){
    if(i > n) return 0;
    if(memo[i] != -1) return memo[i];
    memo[i] = (a[i]==0);
    if(i + k > n) return (memo[i] = memo[i] + pref[n] - pref[i]);
    return (memo[i] = memo[i] + min(dp(i+k) + pref[i + k - 1] - pref[i], pref[n] - pref[i]));

}

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        string s; cin >> s;
        pref[0] = 0;
        frr(i, n){
            memo[i] = -1;
            a[i] = s[i-1] - '0';
            pref[i] = pref[i-1] + a[i];
        }
        int ans = INF;
        if(pref[n] == 0){
            cout << "0\n";
            continue;
        }
        frr(i, n){
            ans = min(ans, pref[i-1] + dp(i));
        }
        cout << ans << endl;
    }
}
