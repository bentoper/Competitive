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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

typedef vector<vector<ll>> matrix;

ll N, M, K;

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<ll>(p));
	ll col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j];
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++){
				ll aux = (a[i][k] * col[k])%MOD;
				s = (s + aux)%MOD;

			}
			c[i][j] = s%MOD;
		}
	}
	return c;
}

matrix id(ll n) {
	matrix c(n, vector<ll>(n));
	for(int i = 0; i < n; i++) c[i][i] = 1;
	return c;
}

matrix matrixExp(matrix a, ll n) {
	if (n == 0) return id(a.size());
	matrix c = matrixExp(a, n/2);
	c = c*c;
	if (n%2 != 0) c = c*a;
	return c;
}


int main() {
	cin >> N >> M >> K;
	matrix mult(M, vector<ll>(M, 1));
	matrix base(M, vector<ll>(1, 1));
	fr(i, K){
		char a; char b;
		cin >> a >> b;
		mult[(a > 'Z')?(a - 'a'):(a - 'A' + 26)][(b > 'Z')?(b - 'a'):(b - 'A' + 26)] = 0;
	}
	if(M == 1){
		cout << M - K << endl;
		return 0;
	}
	mult = matrixExp(mult, N - 1);
	mult = mult*base;
	ll out = 0;
	fr(i, M){
		out = (out + mult[i][0])%MOD;
		
	}
	cout << out; gnl;	
}
