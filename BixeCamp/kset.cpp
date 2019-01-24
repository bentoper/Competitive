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

ll n, k;
int used[112345];
vector<ll> v, even, odd;

int main(){
	scanf("%lld%lld", &n, &k);
	fr(i, n){
		ll aux; scanf("%lld", &aux);
		v.pb(aux);
	}
	sort(all(v));
	if(k == 1){
		printf("%lld\n", n);
		return 0;
	}
	fr(i, n){
		if(used[i]) continue;
		ll x = v[i];
		ll crawler = lower_bound(all(v), k*x) - v.begin();
		even.pb(i);
		while(crawler < n && v[crawler] == k*x){
			if(even.size() > odd.size()){
				odd.pb(crawler);
			}
			else{
				even.pb(crawler);
			}
			x = v[crawler];
			crawler = lower_bound(all(v), k*x) - v.begin(); 
		}
		if(odd.size() != 0){
			if(even.size() > odd.size()){
				fr(j, odd.size()){
					used[odd[j]] = 2;
				}
				odd.clear();
				fr(j, even.size()){
					used[even[j]] = 1;
				}
				even.clear();
			}
			else{
				fr(j, odd.size()){
					used[odd[j]] = 1;
				}
				odd.clear();
				fr(j, even.size()){
					used[even[j]] = 2;
				}
				even.clear();
			}
		}
		else{
			even.clear();
			used[i] = 1;
		}
	}
	int counter = 0;
	fr(i, n){
		if(used[i] == 1) counter++;
	}
	printf("%d\n", counter);
}
