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
const ll MOD = 1000000;

ll N, K, L;

matrix mult(2, vector<ll>(2));
matrix base(2, vector<ll>(1));


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
				ll plc = (a[i][k] * col[k])%MOD;
				s = (s + plc)%MOD;
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


int main(){
	while(scanf("%lld%lld%lld", &N, &K, &L) == 3){
		mult = {{K%MOD, L%MOD}, {1, 0}};
		base = {{K%MOD}, {1}};
		if(N >= 10){
			mult = matrixExp(mult, N/5-1);
			mult = mult*base;
			mult[0][0] %= MOD;
			ll out = mult[0][0];
			if(out >= 10){
				if(out >= 100){
					if(out >= 1000){
						if(out >= 10000){
							if(out >= 100000){
								printf("%lld\n", out);
							}
							else printf("0%lld\n", out);

						}
						else printf("00%lld\n", out);
					}
					else printf("000%lld\n", out);


				}
				else printf("0000%lld\n", out);
			}
			else{
				printf("00000%lld\n", out);
			}
		}
		else{
			ll out = K%MOD;
			if(out >= 10){
				if(out >= 100){
					if(out >= 1000){
						if(out >= 10000){
							if(out >= 100000){
								printf("%lld\n", out);
							}
							else printf("0%lld\n", out);

						}
						else printf("00%lld\n", out);
					}
					else printf("000%lld\n", out);


				}
				else printf("0000%lld\n", out);
			}
			else{
				printf("00000%lld\n", out);
			}
		}
	}
}
