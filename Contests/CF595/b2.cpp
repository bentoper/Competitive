#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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
const int N = 2e5 + 1;

int p[N], pos[N], ans[N], vis[N];

int main(){
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        frr(i, n){
            cin >> p[i];
            pos[i] = i;
            ans[i] = 3e5;
            vis[i] = 0;
        }
        frr(i, n){
            if(vis[i] == 0){
                vi idx;
                idx.pb(i);
                vis[i] = 1;
                int s = p[i], cnt = 1;
                while(s != i){
                    vis[s] = 1;
                    idx.pb(s);
                    s = p[s];
                    cnt++;
                }
                for(int v: idx){
                    ans[v] = cnt;
                }
            }
        }
        frr(i, n){
            cout << ans[i] << " \n"[i==n];
        }
    }
}
