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
typedef vector<vector<ll>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N, M, z[] = {0, 0, 1, 2, 4};

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	//assert(a[0].size() == b.size());
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<ll>(p));
	ll col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j]; //cache friendly
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++){
				ll vaca = a[i][k]%MOD;
				ll porco = col[k]%MOD;
				vaca = (vaca*porco)%MOD;
				if(vaca < 0) vaca += MOD;
				s = (s%MOD + vaca)%MOD;
				while(s < 0) s += MOD;
			}
			c[i][j] = s%MOD;
		}
	}
	return c;
}

matrix id(int n) {
	matrix c(n, vector<ll>(n));
	for(int i = 0; i < n; i++) c[i][i] = 1;
	return c;
}

matrix matrixExp(matrix a, int n) {
	if (n == 0) return id(a.size());
	matrix c = matrixExp(a, n/2);
	c = c*c;
	if (n%2 != 0) c = c*a;
	return c;
}


ll solve(int start, int finish){
	if(finish <= 3){
		return z[finish+1] - z[start];
	}
	int s = -1;
	if(start <= 4) s = z[start];
	matrix fib(4, vector<ll>(1));
	fib = {{4}, {2}, {1}, {0}};
	matrix mult(4, vector<ll>(4));
	mult = {{2, 0, -1, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
	matrix ans = matrixExp(mult, M - 3)*fib;
	if(s != -1) return ((ll)ans[0][0] - (ll)s + (ll)MOD)%MOD;
	mult = matrixExp(mult, N - 4)*fib;
	//dbg(ans[0][0]); dbg(mult[0][0]);
	return ((ll)ans[0][0] - (ll)mult[0][0] + (ll)MOD)%MOD;
}

int main() {
	rvr(t);
	while(t--){
		scanf("%d%d", &N, &M);
		printf("%lld\n", solve(N, M));		
	}
	
}
