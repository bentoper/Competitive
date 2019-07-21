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

int n, a[123];
ll s = 0;
vi ans;

int main(){
	cin >> n;
	fr(i, n){
		cin >> a[i];
		s += a[i];
	}

	bool consegui = 0;

	ll curr = a[0];

	ans.pb(1);

	while(curr < s/2 + 1){
		fr(i, n){
			if(i == 0) continue;
			if(a[i] != -1 && a[0] >= 2*a[i]){
				ans.pb(i+1);
				consegui = 1;
				curr += a[i];
				a[i] = -1;

			}
		}
		if(!consegui){
			cout << 0 << endl;
			return 0;
		}
		consegui = 0;
	}

	cout << ans.size() << endl;

	fr(i, ans.size()) cout << ans[i] << " \n"[i == ans.size()-1];

}
