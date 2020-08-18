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
const int N = 1e5 + 1;

int arr[N];
int memo[N][6][2];
int n, k, z;

int dp(int i, int lf, int lt){
    if(i == n - 1) return arr[i];
    if(k == i + 2*(z-lf)) return arr[i];
    int& pdm = memo[i][lf][lt];
    if(pdm != -1) return pdm;
    pdm = arr[i];
    if(!lt && i && lf){
        pdm += dp(i-1, lf - 1, 1);
    }
    pdm = max(pdm, arr[i] + dp(i+1, lf, 0));
    return pdm;
}

int main(){
    rvr(t);
    while(t--){
        scanf("%d%d%d", &n, &k, &z);
        fr(i, n){
            scanf("%d", &arr[i]);
            fr(j, z+1){
                fr(k, 2){
                    memo[i][j][k] = -1;
                }
            }
        }
        printf("%d\n", dp(0, z, 0));
    }
}
