#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%lld%c", x[i], " \n"[i==n-1]);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 212345;


int d[N], n;

ll ans = 0;

ll prsum[N];
pair<ll, int> sufsum[N]; //sz pos
int aa = -1, bb;

int main(){
    scanf("%d", &n);
    sufsum[0].first = 0;
    sufsum[0].second = 0;
    fr(i, n) scanf("%d", &d[i]);
    fr(i, n){
        prsum[i+1] += (ll)d[i] + prsum[i];
        sufsum[i + 1] = mp(sufsum[i].first + d[n - i - 1], n - i);
    }
    sort(sufsum+1, sufsum+n+1);
    frr(i, n-1){
        int pos = lower_bound(sufsum+1, 1+sufsum + n, mp(prsum[i], i + 1)) - sufsum;
        if(pos == n+1) pos--;
        if(sufsum[pos].first == prsum[i] && sufsum[pos].second > i){
            ans = max(ans, prsum[i]);
        }
    }
    printf("%lld\n", ans);
    
}