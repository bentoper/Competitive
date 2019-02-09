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

#define MAXN 	11234
#define LMAXN	20		//ceil(log2(MAXN))


int memo[MAXN][LMAXN + 1], pai[MAXN];
int hgt[MAXN];
int n, clk = 1;

int lca(int a, int b){

	if(hgt[a] < hgt[b])	swap(a,b);

	for(int i = LMAXN;i >= 0;i--)
		if(hgt[a] - (1<<i) >= hgt[b])
			a = memo[a][i];

	if(a==b)	return a;

	for(int i = LMAXN - 1; i >=0 ; i--){ 
		
		if(memo[a][i]!=-1 && memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}

	}

	return memo[b][0];

}

int calcheight(int i){
	if(pai[i] == -1) return hgt[i] = 0;
	if(hgt[i] != -1) return hgt[i];
	else return hgt[i] = calcheight(pai[i]) + 1; 
}

int main(){
	rvr(t);
	while(t--){
		ms(memo, -1);
		ms(hgt, -1);
		ms(pai, -1);	
		cin >> n;
		frr(i, n){
			int m; cin >> m;
			fr(j, m){
				int aux; cin >> aux;
				pai[aux] = i;
			}
		}
		frr(i, n){ 
			memo[i][0] = pai[i];
			if(hgt[i] == -1) hgt[i] = calcheight(i);
		}
		for(int j = 1; j < LMAXN; j++){
			frr(i, n){
				if(memo[i][j-1] != -1){
					memo[i][j] = memo[memo[i][j-1]][j-1];
				}
			}
			
		}
		rvr(q);
		printf("Case %d:\n", clk++);
		while(q--){
			rvr(a); rvr(b);
			printf("%d\n", lca(a, b));
		}
	}
}