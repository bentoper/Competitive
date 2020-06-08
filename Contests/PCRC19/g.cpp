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
    int ret[] = {0, 0, 0, 0};
    int x, y;
    scanf("%d%d", &x, &y);
    fr(i, 4) scanf("%d", &ret[i]);
    if(x >= ret[0] && x <= ret[2] && y <= ret[1]){
        printf("%d.000\n", ret[1] - y);
    }
    else if(x >= ret[2] && y >= ret[1] && y <= ret[3]){
        printf("%d.000\n", x - ret[2]);
    }
    else if(x >= ret[0] && x <= ret[2] && y >= ret[3]){
        printf("%d.000\n", y - ret[3]);
    }
    else if(x <= ret[0] && y >= ret[1] && y <= ret[3]){
        printf("%d.000\n", ret[0] - x);
    }
    else{
        double ans = INF;
        fr(i, 4){
            int xx = ret[((i%3)!=0)*2], yy = ret[(i > 1)*2 + 1];
            ans = min(ans, sqrt( (double)((x-xx)*(x-xx) + (y-yy)*(y-yy)) ));
        }
        printf("%.3lf\n", ans);
    }
}
