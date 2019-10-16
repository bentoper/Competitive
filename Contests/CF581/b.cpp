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

int N, L, R;

ll minsum(int n, int l, int r){
	ll plc = 0;
	ll a = 2;
	fr(i, l - 1){
		plc += a;
		a *= 2;
	}
	n -= (l-1);
	plc += n;
	return plc;
}

ll maxsum(int n, int l, int r){
	if(r == 1) return n;
	ll plc = 0;
	plc += 1;
	n--;
	r--;
	ll a = 2;
	fr(i, r - 1){
		plc += a;
		a *= 2;
		n--;
	}
	fr(i, n){
		plc += a;
	}

	return plc;
}

int main(){
	cin >> N >> L >> R;
	cout << minsum(N, L, R) << " " << maxsum(N, L, R) << endl;
}
