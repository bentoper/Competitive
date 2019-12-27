#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%lld%c", x[i], " \n"[i==n-1])

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


vll p;

int main(){
    ll b = 1;
    while(b <= 1e18 && b > 0){
        p.pb(b);
        b *= 3ll;
    }
    int q; cin >> q;
    while(q--){
        ll n; cin >> n;
        vi fac;
        while(n != 0){
            fac.pb(n%3ll);
            n /= 3ll;
        }
        int l0 = -1;
        bool cagou = false;
        for(int i = fac.size() - 1; i >= 0; i--){
            if(fac[i] == 0) l0 = i;
            else if(fac[i] == 2){
                if(l0 == -1){
                    cagou = true;
                    break;
                }
                else{
                    for(int j = 0; j < l0; j++){
                        fac[j] = 0;
                    }
                    fac[l0]=1;
                    break;
                }
            }
        }
        if(cagou){
            if(p.size() <= fac.size()){
                cout << "1350851717672992089" << endl;
            }
            else cout << p[fac.size()] << endl;
        }
        else{
            ll ans = 0, bb = 1;
            for(auto b: fac){
                ans += bb*(ll)b;
                bb *= 3ll;
            }
            cout << ans << endl;
        }
    }

}
