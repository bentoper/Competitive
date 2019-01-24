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

int n, k, a[112345], t[112345], sum;
ll accu[112345];

int main(){
	scanf("%d%d", &n, &k);
	fr(i, n){
		scanf("%d", &a[i]);
	}
	fr(i, n){
		scanf("%d", &t[i]);
		if(t[i]){
			sum += a[i];
			accu[i+1] = accu[i]; 
		}
		else accu[i+1] = accu[i] + a[i];
		
	}
	int i = 0;
	ll maxsum = 0;
	while(i <= n - k + 1){
		maxsum = max(maxsum, accu[i + k]-accu[i]);
		i++;
	}
	printf("%lld\n", maxsum+sum);
}
