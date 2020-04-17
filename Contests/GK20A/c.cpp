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

vi S;

int main(){
    rvr(t);
    int clk = 0;
    while(t--){
        int n, k; scanf("%d%d", &n, &k);
        S.clear();
        int last = 0;
        fr(i, n){
            rvr(a);
            if(i != 0) S.pb(a - last);
            last = a;
        }
        sort(all(S));
        int mx = S[n-2];
        int l = 1, r = mx;
        int ans = INF;
        while(l <= r){
            int mid = (l + r)>>1;
            int plc = k;
            int j = n - 2;
            bool deu = true;
            while(j >= 0 && S[j] > mid){
                int x = (S[j]-1)/mid;
                if(plc < x){
                    deu = false;
                    break;
                }
                plc -= x;
                j--;
            }
            if(deu){
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        printf("Case #%d: %d\n", ++clk, ans);
    }
}
