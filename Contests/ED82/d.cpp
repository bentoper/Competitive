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

ll M[100];

int main(){
    rvr(t);
    while(t--){
        ms(M, 0);
        ll n; int m; scanf("%lld%d", &n, &m);
        ll sm = 0;
        fr(i, m){
            ll a; scanf("%lld", &a);
            sm += a;
            int j = 0;
            while(1<<j < a) j++;
            M[j] += a;
        }
        if(sm < n){
            printf("-1\n");
            continue;
        }
        ll plc = n, cursum = 0;
        ll ans = 0;
        for(ll i = 0; 1ll<<i <= plc; i++){
            if(!(1ll<<i & plc)) {cursum += M[i]; continue;}
            if(M[i] != 0){
                M[i] -= 1<<i;
                cursum += M[i];
                plc -= 1<<i;
            }
            else{
                if(cursum >= 1<<i) cursum -= 1<<i, plc -= 1<<i;
                else{
                    int j = i + 1;
                    while(M[j] == 0) j++;
                    while(j > i){
                        M[j] -= 1<<j;
                        M[(j-1)] += 1<<j;
                        j--;
                        ans++;
                    }
                    M[j] -= 1<<j;
                    plc -= 1<<j;
                }
            }
        }
        printf("%lld\n", ans);
    }
}
