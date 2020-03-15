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
const int N = 2e3 + 1;

int memo[N][N];
int a[N], n, l, r, h;
ll pref[N];

int dp(int i, int j){
    if(i == n) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    int deu = ((pref[i] - j)%h >= l && (pref[i] - j)%h <= r);
    int deu2 = ((pref[i] - j - 1)%h >= l && (pref[i]- j - 1)%h <= r);

    return memo[i][j] = max(deu+dp(i+1, j), deu2+dp(i+1, j+1));

}


int main(){
    scanf("%d%d%d%d", &n, &h, &l, &r);
    ms(memo, -1);
    fr(i, n){
        scanf("%d", &a[i]);
        if(i > 0) pref[i] = pref[i-1] + (ll)a[i];
        else pref[i] = a[i];
    }
    printf("%d\n", dp(0, 0));
}
