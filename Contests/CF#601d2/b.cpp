#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x);
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
const int N = 2123;


int n, m, w[N];

vii v;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        v.clear();
        ll sum = 0;
        scanf("%d%d", &n, &m);
        frr(i, n) {
            scanf("%d", &w[i]);
            v.pb(mp(w[i], i));
            sum += (ll)w[i];
        }
        if(m <= n - 1 || n == 2){
            printf("-1\n");
            continue;
        }
        sort(all(v));
        ll ans = 2*sum + (ll)(m - n)*(ll)((ll)v[0].first + (ll)v[1].first);
        printf("%lld\n", ans);
        fr(i, n){
                if(i == n - 1){
                    printf("%d %d\n", v[n - 1].second, v[0].second);
                }
                else printf("%d %d\n", v[i].second, v[i+1].second);    
        }
        fr(i, m - n){
            printf("%d %d\n", v[0].second, v[1].second);
        }
    }
}
