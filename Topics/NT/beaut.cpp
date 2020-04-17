//http://codeforces.com/problemset/problem/300/C
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
const int MOD = 1000000007;

int a, b, n, amt;

ll perm[1000000];

ll fastxp(ll z, ll x){
	//dbg(z);
	if(x == 0) return 1;
	if(x == 1) return z;
	return (fastxp((z*z)%MOD, x/2)*((x%2==1)?z:1)%MOD)%MOD;
}

bool solve(ll t){
	while(t > 0){
		int plc = t%10;
		if(plc == a || plc == b) t /= 10;
		else return false;
	}
	return true;
}

void gen(){
	ll base = n;
	perm[0] = 1;
	perm[1] = n;
	for(int i = 2; i <= n/2; i++){
		base *= n - i + 1;
		base %= MOD;
		//dbg(fastxp(i, MOD-1));
		base *= fastxp(i, MOD-2);
		base %= MOD;
		perm[i] = base;
		//dbg(i); dbg(perm[i]);
	}
}

int main(){
	cin >> a >> b >> n;

	amt = 0;
	gen();
	
	for(int i = 0; i <= n; i++){
		ll test = (n-i)*a + i*b;
		if(solve(test)){
			amt += perm[min(i, n-i)];
			amt %= MOD;
			
		} 
	}

	cout << amt << "\n"; 
}
