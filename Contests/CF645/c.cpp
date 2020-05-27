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

set<ll> sums;

int d1, d2;


int main(){
    rvr(t);
    while(t--){
        ll x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        ll xdiff = x2 - x1, ydiff = y2 - y1;
        ll ans = min(xdiff, ydiff)*min(xdiff, ydiff) + 1;
        if(xdiff == 0 || ydiff ==0){
            printf("1\n");
            continue;
        }
        //printf("xdiff %lld ydiff %lld\n", xdiff, ydiff);
        if(xdiff < ydiff){
            ans += xdiff*(ydiff - xdiff);
        }
        else if(ydiff < xdiff){
            ans += ydiff*(xdiff - ydiff);
        }
        printf("%lld\n", ans);
    }
}
