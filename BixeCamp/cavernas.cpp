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

int n, m, trips[10000];

int main(){
	scanf("%d %d", &n, &m);
	fr(i, n){
		scanf("%d", &trips[i]);
	}
	ll sz = 0, last = 0;
	fr(i, n){
		if(sz > trips[i] && sz > m - trips[i]){
			printf("-1\n"); return 0;
		}
		else if(trips[i] >= sz && m - trips[i] < sz){
			sz = trips[i];
			last += sz;
		}
		else if(m - trips[i] >= sz && trips[i] < sz){
			sz = m - trips[i];
			last += sz;
		}
		else{
			sz = min(trips[i], m - trips[i]);
			last += sz;
		}
	}
	printf("%lld\n", last);
}
