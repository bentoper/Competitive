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
    fastio;
    int t; cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y; 
        int qnt = 0;
        vector<vi> grid;
        fr(i, n){
            vi plc;
            fr(j, m){
                char c; cin >> c;
                plc.pb(c=='.'?1:0);
                if(plc[j]) qnt++;
            }
            grid.pb(plc);
        }
        if(y >= 2*x){
            cout << qnt*x << endl;
            continue;
        }
        int ans = 0;
        fr(i, n){
            int cnt = 0;
            fr(j, m){
                if(grid[i][j]){
                    cnt++;
                }
                else{
                    if(cnt%2){
                        ans += (cnt/2)*y + x;
                    }
                    else ans += y*(cnt/2);
                    cnt = 0;
                }
            }
            if(cnt%2){
                ans += (cnt/2)*y + x;
            }
            else ans += y*(cnt/2);
            cnt = 0;
        }
        cout << ans << endl;
    }
}
