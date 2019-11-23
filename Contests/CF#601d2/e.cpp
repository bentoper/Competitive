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
const int N = 112345;

int n, a[N];
ll sum = 0;


ll solve(int k){
	if(k == 1) return llINF;
	ll ans = 0;
	vi v;
	ll plc = 0;
	int i = 0, j = 0;
	int med = -1, cur = 0;
	while(i < n && j < sum/k){
		v.clear();
		plc = 0;
		cur = 0;
		while(cur < k){
			cur += a[i];
			if(a[i]){
				v.pb(i);
				if(cur == (k/2 + k%2)) med = i;
			}
			i++;
		}
		for(auto x: v){
			plc += abs(x - med); 

		}
		ans = ans + (ll) plc;
		j++;
	}
	return ans;
}

int main(){
    
    scanf("%d", &n);
    fr(i, n){
        scanf("%d", &a[i]);
        sum += a[i];
    }
	if(sum == 1){
		printf("-1\n");
		return 0;
	}
	ll ans = llINF;
	for(int x = 1; x*x <= sum; x++){
		if(sum%x == 0){
			ans = min(ans, solve(x));
			ans = min(ans, solve(sum/x));
		}
	}

	printf("%lld\n", ans);

}
