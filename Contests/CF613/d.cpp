#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])

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

int n;

vi a;

int solve(vi &v, int i){
    if(v.size() == 0 || i < 0) return 0;
    vi on, off;
    int sz = v.size();
    fr(j, sz){
        if(v[j]&(1<<i)) on.pb(v[j]);
        else off.pb(v[j]);
    }
    if(on.size() == 0) return solve(off, i - 1);
    if(off.size() == 0) return solve(on, i - 1);
    return min(solve(off, i - 1), solve(on, i - 1)) + (1<<i);
}


int main(){
    int lmax = 0;
    int mx = -1;
    scanf("%d", &n);
    a.resize(n);
    fr(i, n) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", solve(a, 29));

}
