#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

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

int qnt[9*N], suf[N + 1];
int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vi a(n);
        fr(i, n) a[i] = s[i] - '0', suf[i] = 0;
        fr(i, 9*n + 1) qnt[i] = 0; 
        suf[n] = 0;
        ll tot = 0;
        ll ans = 0, sm = 0;
        fr(i, n){
            int cur = n - i - 1;
            tot += a[i];
            suf[cur] = suf[cur + 1] + a[cur];
            if(suf[cur] == n - 1 - cur + 1) ans++;
            if(cur) qnt[(cur + suf[cur])]++;
        }
        fr(i, n){
            if(i < n-1) qnt[suf[i+1] + i+1]--;
            sm += a[i];
            if(sm == i + 1 && i != n-1) ans++;
            ans += qnt[tot + i + 1 - sm];
        }
        printf("%lld\n", ans);
    }
}

//j - i - 1 = S - pref[i] - pref[j]

