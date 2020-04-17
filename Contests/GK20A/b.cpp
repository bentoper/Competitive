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
const int N = 51;
int memo[N][N*30];

int n, k;

int stk[N][N];

int dp(int i, int lf){
    if(lf == 0) return 0;
    if(i == n) return -INF;
    if(memo[i][lf] != -1) return memo[i][lf];
    int j = 1, beaut = 0;
    memo[i][lf] = dp(i + 1, lf);
    while(j <= lf && j <= k){
        int plc = dp(i + 1, lf - j);
        beaut += stk[i][j-1];
        //printf("%d %d beaut %d\n", i, lf, beaut); 
        j++;
        if(plc == -INF) continue;
        memo[i][lf] = max(memo[i][lf], plc + beaut);
    }
    return memo[i][lf];
}

int main(){
    rvr(t);
    int clk = 0;
    while(t--){
        scanf("%d%d", &n, &k);
        rvr(p);
        ms(memo, -1);
        fr(i, n){
            fr(j, k){
                scanf("%d", &stk[i][j]);
            }
        }
        printf("Case #%d: %d\n", ++clk, dp(0, p));
    }
}
