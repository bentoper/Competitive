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
        int a, b, c, d;
        int x[3], y[3];
        scanf("%d%d%d%d", &a, &b, &c, &d);
        fr(i, 3){
            scanf("%d%d", &x[i], &y[i]);
        }
        if(b - a > x[2] - x[0] || a - b > x[0] - x[1] || c - d > y[0] - y[1] || d - c > y[2] - y[0]){
            printf("No\n");
            continue;
        }
        int cnt = 0, nz = 0;
        if(a) nz++;
        if(a && x[0] - 1 < x[1]) cnt++;
        if(b) nz++;
        if(b && x[0] + 1 > x[2]) cnt++;
        if(cnt == 2){
            printf("No\n");
            continue;
        }
        int plc = cnt;
        if(c) nz++;
        if(c && y[0] - 1 < y[1]) cnt++;
        if(d) nz++;
        if(d && y[0] + 1 > y[2]) cnt++;
        if(cnt - plc == 2){
            printf("No\n");
            continue;
        }
        if(nz == cnt) printf("No\n");
        else printf("Yes\n");
    }
}
