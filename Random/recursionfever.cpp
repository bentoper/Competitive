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

ll memo[1001], a[1001];
ll n, k, m;

ll dp(ll i){
	if(memo[i] != -llINF) return memo[i];
	memo[i] = 0;
	frr(j, n){
		memo[i] += (a[j]*dp(i-j))%m;
		memo[i] %= m;
	}
	return memo[i];
}

int main(){
	scanf("%lld%lld%lld", &n, &k, &m);
	frr(i, n){
		scanf("%lld", &a[i]);
	}
	frr(i, n){
		scanf("%lld", &memo[i]);
	}
	for(ll i = n + 1; i <= k; i++) memo[i] = -llINF;
	printf("%lld\n", dp(k));
	//frr(i, k) dbg(memo[i]);

}
