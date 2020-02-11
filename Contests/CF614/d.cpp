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
const ll llINF = 2e16;

vll dist;

int main(){
    ll x0, y0, ax, ay, bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
    ll xs, ys, t; scanf("%lld%lld%lld", &xs, &ys, &t);
    int otp = 0;
    ll curx = x0, cury = y0;
    vector<pair<ll, ll>> points;
    while(1){
        points.pb(mp(curx, cury));
        if((llINF - bx)/ax <= curx || (llINF - by)/ay <= cury) break;
        curx = curx*ax + bx, cury = cury*ay + by;
    }
    int sz = points.size();
    fr(i, sz){
        ll used = abs(xs - points[i].first) + abs(ys - points[i].second);
        int j = i, ans = 0;
        while(j < sz){
            if(j != i) used += points[j].first - points[j-1].first + points[j].second - points[j-1].second;  
            if(used <= t) ans++;
            else break;
            j++;
        }
        otp = max(otp, ans);
        used = abs(xs - points[i].first) + abs(ys - points[i].second);
        j = i, ans = 0;
        while(j >= 0 && used <= t){
            if(j != i) used += points[j+1].first - points[j].first + points[j+1].second - points[j].second;  
            if(used <= t) ans++;
            else break;
            j--;
        }
        otp = max(otp, ans);
    }
    printf("%d\n", otp);
}
