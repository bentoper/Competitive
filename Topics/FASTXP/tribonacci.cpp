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
typedef vector<vector<int>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

ll N, M;

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	//assert(a[0].size() == b.size());
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<int>(p));
	int col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j]; //cache friendly
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++)
				s += (ll)((ll)a[i][k] * (ll)col[k])%MOD;
			c[i][j] = s%MOD;
		}
	}
	return c;
}

matrix id(int n) {
	matrix c(n, vector<int>(n));
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

void printmatrix(matrix & a) {
	int n = (int)a.size();
	int m = (int)a[0].size();
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%lld", &N);
	while(N != 0){
		matrix inp(3, vector<int>(3));
		fr(i, 3){
			inp[0][i] = 1;
		}
		inp[1][0] = 1;
		frr(i, 2) inp[1][i] = 0;
		inp[2][1] = 1;
		inp[2][0] = inp[2][2] = 0;
		matrix trib(3, vector<int>(1));
		trib[0][0] = 2;
		trib[1][0] = 1;
		trib[2][0] = 0;
		if(N <= 3) printf("%lld\n", N-1);
		else{
			inp = matrixExp(inp, N - 3);
			//printmatrix(inp);
			inp = inp*trib;
			printf("%d\n", inp[0][0]);
		} 
		scanf("%lld", &N);	
	}	
}
