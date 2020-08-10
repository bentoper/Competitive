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
const int N = 2e5 + 1;


int main(){
    rvr(t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        vi vec(n);
        fr(i, n) scanf("%d", &vec[i]), vec[i] %= k;
        sort(all(vec));
        reverse(all(vec));
        while(!vec.empty() && vec[vec.size() - 1] == 0) vec.pop_back();
        if(vec.empty()){
            printf("0\n");
            continue;
        }
        ll ans = 1;
        n = vec.size();
        int last = -1, cur = 0;
        fr(i, n){
            if(vec[i] == last) cur++;
            else cur = 1;
            ans = max(ans, (ll)(cur - 1)*(ll)k + (ll)(k - vec[i]));
            last = vec[i];
        }
        printf("%lld\n", ans + 1);
    }
}
