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
const int N = 1e6 + 1;

int n;
vi mvec[N];
int minfreq[N];
bool asc[N];

int main(){
    scanf("%d", &n);
    ll ascc = 0;
    fr(i, n){
        int l; scanf("%d", &l);
        int mn = 1e7, mx = -1;
        int cnt = 0;
        fr(j, l){
            rvr(a);
            mx = max(mx, a);
            if(mn >= a) cnt++;
            mn = min(mn, a);
        }
        mvec[i].pb(mx);
        if(cnt == l){
            minfreq[mn]++;
        }
        else{
            asc[i] = 1;
            ascc++;
        } 
    }
    frr(i, (int)1e6){
        minfreq[i] = minfreq[i-1] + minfreq[i];
    }
    ll ans = 0;
    //dbg(ascc);
    fr(i, n){
        //dbg(ans);
        if(asc[i]){
            ans += (ll)n;
            continue;
        }
        if(mvec[i][0] > 0) ans += (ll)minfreq[mvec[i][0] - 1];
        ans += ascc;
    }
    printf("%lld\n", ans);
}
