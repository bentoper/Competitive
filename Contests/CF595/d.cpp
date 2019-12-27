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

int l[N], r[N];

vi st[N], fin[N];

set<pii> s;


int main(){
    int n, k; scanf("%d%d", &n, &k);
    int ed = -1;
    frr(i, n){
        int a, b;
        scanf("%d%d", &l[i], &r[i]);
        ed = max(ed, r[i]);
        st[l[i]].pb(i);
        fin[r[i]].pb(i);
    }
    int m = 0, curr = 0;
    vi ans;
    frr(i, ed){
        for(auto seg: st[i]){
            s.insert(mp(r[seg], seg));
            curr++;
        }
        while(curr > k){
            auto it = s.rbegin(); 
            pii p = *it;
            ans.pb(p.second);
            s.erase(*it);
            curr--;
        }
        for(auto seg: fin[i]){
            if(s.find(mp(i, seg)) != s.end()){
                s.erase(mp(i, seg));
                curr--;
            }
        }
    }
    printf("%d\n", (int) ans.size());
    pv(ans, ans.size());


}
