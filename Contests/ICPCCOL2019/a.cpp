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

map<pll, set<pll>> S;
set<int> H, V;

pll build(ll top, ll bot, ll x, ll y){
    int um = 1; 
    ll tp = y*bot - x*top;
    ll d = __gcd(abs(tp), abs(bot));
    bot /= d, tp /= d;
    return mp(tp, bot);
}

int main(){
    rvr(t);
    while(t--){
        rvr(n);
        S.clear();
        H.clear();
        V.clear();
        fr(i, n){
            rvr(x1); rvr(y1); rvr(x2); rvr(y2);
            if(x1 - x2 == 0){
                V.insert(x1);
                continue;
            }
            else if(y1 - y2 == 0){
                H.insert(y1);
                continue;
            }
            if(x2 < x1){
                swap(x1, x2);
                swap(y1, y2);
            }
            ll top = y2 - y1, bot = x2 - x1;
            ll d = __gcd(abs(top), abs(bot));
            top /= d, bot /= d;
            if(bot < 0){
                if(top < 0){
                    top *= -1;
                }
                else top *= -1;
                bot *= -1;
            }
            S[mp(top, bot)].insert(build(top, bot, x1, y1));            
        }
        ll ans = 0;
        for(auto p: S){
            ll top = -p.first.second, bot = p.first.first;
            if(bot < 0){
                if(top < 0){
                    top *= -1;
                }
                else top *= -1;
                bot *= -1;
            }
            ans += (ll)(p.second.size())*(ll)(S[mp(top, bot)].size());
        }
        ans /= 2ll;
        ans += (ll)H.size()*(ll)V.size();
        printf("%lld\n", ans);
    }
}
