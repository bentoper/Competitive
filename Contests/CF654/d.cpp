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

int grid[301][301];

int main(){
    rvr(t);
    while(t--){
        int n, k; scanf("%d%d", &n, &k);
        fr(i, n){
            fr(j, n) grid[i][j] = 0;
        }
        int x0 = 0, y0 = 0;
        while(k > 0){
            fr(j, n){
                grid[(x0 + j)%n][(y0 + j)%n] = 1;
                k--;
                if(!k) break;
            }
            x0++;
        }
        ll ans = 0, mx[] = {-1, -1}, mn[] = {400, 400};
        fr(i, n){
            int curr = 0, curc = 0;
            fr(j, n){
                curr += grid[i][j];
                curc += grid[j][i];
            }
            mx[0] = max(mx[0], (ll)curr);
            mx[1] = max(mx[1], (ll)curc);
            mn[0] = min(mn[0], (ll)curr);
            mn[1] = min(mn[1], (ll)curc);
        }
        printf("%lld\n", (mx[0] - mn[0])*(mx[0] - mn[0]) + (mx[1] - mn[1])*(mx[1] - mn[1]));
        fr(i, n){
            fr(j, n) printf("%d", grid[i][j]);
            printf("\n");
        }
    }
}
