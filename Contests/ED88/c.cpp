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

int main(){
    rvr(t);
    while(t--){
        int h, c, t; scanf("%d%d%d", &h, &c, &t);
        if(t <= ((double)(h + c))/2.0){
            printf("2\n");
            continue;
        }
        ll l = 1, r = 1e12, ans = 2;
        double mindiff = INF;
        while(l <= r){
            ll mid = (l + r)/2ll;
            ll qnt = 2ll*mid - 1ll;
            ll plc = (mid* (ll)h) + (mid - 1ll)*(ll)c;
            double temp = (double)plc/(double)qnt;
            if(temp >= t){
                if(mindiff > abs((double)t - temp)){
                    mindiff = abs((double)t - temp);
                    ans = qnt;
                }
                l = mid + 1ll;
            }
            else{
                if(mindiff > abs((double)t - temp)){
                    mindiff = abs((double)t - temp);
                    ans = qnt;
                }
                r = mid - 1ll;
            }
        }
        for(ll i = -8; i <= 8; i+= 2){
            if(ans + i >= 1){
                ll plc = (ans + i + 1ll)/2ll;
                plc *= (ll)h;
                plc += ((ans + i)/2ll)*(ll)(c);
                if(mindiff >= abs((double)plc/(double)(ans+i) - t)){
                    ans = min(ans, ans + i);
                    mindiff = abs((double)plc/(double)(ans+i) - t);
                }
            }
        }

        if(abs(((double)(h + c))/2.0 - (double)t) <= mindiff){
            printf("2\n");
            continue;
        }
        printf("%lld\n", ans);
    }
}
