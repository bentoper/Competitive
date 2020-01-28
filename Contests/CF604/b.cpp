#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0, vacao = n;i<vacao;i++)
#define frr(i,n)	for(int i=1, vacao = n;i<=vacao;i++)
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
const int N = 2e5 + 1;

int perm[N], pos[N];

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        fr(i, n) scanf("%d", &perm[i]), pos[perm[i]] = i;
        int l = 0, r = n-1, dir = -1;
        bool achou = false;
        vector<int> ans(n+1, false);
        int mn = pos[1], mx = pos[1];
        ans[1] = 1;
        ans[n]  = 1;
        for(int i = 2; i <= n; i++){
            if((pos[i] == mn - 1 || pos[i] == mx + 1) && ans[i-1]){
                ans[i] = 1;
                mn = min(pos[i], mn);
                mx = max(pos[i], mx);
                continue;
            }
            mn = min(pos[i], mn);
            mx = max(pos[i], mx);
            if(mx - mn + 1 == i){
                ans[i] = 1;
            }
        }
        frr(i, n){
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
