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
const ll llINF = INT64_MAX;
const int N = 1123456;
const int MAX_SIEVE = 1123456;

int n;
ll a[N], sum = 0;

vector<int> prim;
int mark[MAX_SIEVE];
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i);
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

ll solve(ll sm, ll k){
    ll prosum = 0;
    ll ans = 0;
    fr(i, n-1){
        prosum += a[i];
        ans += min(k - prosum%k, prosum%k);
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    fr(i, n){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if(sum == 1){
        printf("-1\n");
        return 0;
    }
    crivo();
    ll scpoy = sum, ans = llINF;
    for(auto x: prim){
        if(sum%x == 0){
            while(sum%x == 0) sum /= x;
            ans = min(ans, solve(scpoy, x));
        }
    }
    if(sum != 1) ans = min(ans, solve(scpoy, scpoy));

    printf("%lld\n", ans);
}
