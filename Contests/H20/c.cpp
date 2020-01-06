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
const int N = 3e5 + 1;

ll fat[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    fat[0] = 1;
    frr(i, n){
        fat[i] = fat[i-1]*(ll)i;
        fat[i] %= m;
    }
    ll ans = 0;
    frr(i, n){
        ll plc = fat[i]*fat[n-(i-1)];
        plc %= m;
        plc *= (n - (i-1));
        ans += (plc)%m;
        ans %= m;
    }
    printf("%lld\n", ans);

}
