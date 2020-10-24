#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)

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
    rvr(n);
    ll t; scanf("%lld", &t);
    vi pos, neg;
    int z = 0;
    fr(i, n){
        rvr(a);
        if(a > 0) pos.pb(a);
        else if(a < 0) neg.pb(a);
        else z = 1;
    }
    int ans = 0;
    fr(i, pos.size()){
        if(pos[i] > t) break;
        ans = max(ans, i+1);
    }
    fr(i, neg.size()){
        if(abs(neg[i]) <= t){
            ans = max(ans, (int)neg.size() - i);
            if(!pos.empty()){
                int plc = upper_bound(all(pos), (t - 2*abs(neg[i]))) - pos.begin();
                ans = max(ans, plc + (int)neg.size() - i);
                plc = upper_bound(all(pos), (t - abs(neg[i]))/2) - pos.begin();
                ans = max(ans, plc + (int)neg.size() - i);
            }
        }
    }
    printf("%d\n", ans + z);
}
