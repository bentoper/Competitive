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

int n, k;
vector<pii> divers;

int main(){
	scanf("%d%d", &n, &k);
	int i = 1;
	while(i*i <= n){
		if(n%i == 0){
			divers.pb({i, n/i});
		}
		i++;
	}
	ll answer = llINF;
	fr(j, divers.size()){
		ll num = llINF;
		if(divers[j].second < k) num = (ll)divers[j].first*k + (ll)divers[j].second;
		answer = min(answer, num);
		if(divers[j].first < k) num = (ll)divers[j].first + (ll)divers[j].second*k;
		answer = min(answer, num);
	}
	printf("%lld\n", answer);
}
