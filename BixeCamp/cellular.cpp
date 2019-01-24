#include "bits/stdc++.h"
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
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll n, m, r = 0;
vector<ll> cities, towers;

int main(){
	scanf("%lld%lld", &n, &m);
	ll aux;
	fr(i, n){
		scanf("%lld", &aux);
		cities.pb(aux);
	}
	fr(i, m){
		scanf("%lld", &aux);
		towers.pb(aux);
	}
	fr(i, n){
		ll low = lower_bound(all(towers), cities[i]-r) - towers.begin();
		if(low == m){
			r = abs(cities[i] - towers[m-1]);
		}
		else{
			if(towers[low] <= cities[i] + r) continue;
			else{
				if(low > 0) r = max(r, min(abs(cities[i]-towers[low-1]), abs(cities[i]-towers[low])));
				else r = abs(cities[i]-towers[low]);
			}
		}
	}
	printf("%lld\n", r);
}
