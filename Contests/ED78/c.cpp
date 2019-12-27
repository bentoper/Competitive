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

int n;

vi l, r, lpref;
vector<pii> rpref;

map<int, int> m;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        l.clear();
        r.clear();
        lpref.clear();
        rpref.clear();
        m.clear();
        scanf("%d", &n);
        int diff = 0;
        fr(i, 2*n){
            int a; scanf("%d", &a);
            a = (a==2?1:-1);
            if(i < n) l.pb(a);
            else r.pb(a);
            diff += a;
        }
        if(diff == 0){
            printf("0\n");
            continue;
        }
        reverse(all(l));
        lpref.pb(0);
        frr(i, n){
            lpref.pb(lpref[i-1]+l[i-1]);
            if(i == 1) rpref.pb(mp(r[i-1], i)); 
            else rpref.pb(mp(rpref[i-2].first+r[i-1], i));
            if(m[rpref[i-1].first] == 0){
                m[rpref[i-1].first] = i;
            }
        }
        int ans = INF;
        frr(i, n){
            int pos = lower_bound(all(rpref), mp(diff - lpref[i], 0)) - rpref.begin();
            if(m[diff - lpref[i]] != 0){
                ans = min(ans, i + m[diff - lpref[i]]);
            }
            if(lpref[i] == diff){
                ans = min(ans, i);
            }
        }
        if(m[diff] != 0){
            ans = min(ans, m[diff]);
        }
        printf("%d\n", ans);
    }
}
