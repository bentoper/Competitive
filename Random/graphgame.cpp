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



int memo[100001][2];
int n, w[100001], pai[100001];
vector<int> adj[100001];

int dp(int i, int last){
	if(memo[i][last] != -INF) return memo[i][last];
	int caso[] = {max(0, w[i]), 0};

	for(auto x: adj[i]){
		if(x == pai[i]) continue;
		pai[x] = i;
		caso[1] += dp(x, 0);
		if(last == 0) caso[0] += dp(x, 1);
	}

	if(last) memo[i][last] = caso[1];
	else memo[i][last] = max(caso[1], caso[0]);

	return memo[i][last];
}



int main(){
	scanf("%d", &n);
	fr(i, 100001){
		fr(j, 2) memo[i][j] = -INF;
	}
	fr(i, n-1){
		rvr(aux1); rvr(aux2);
		adj[aux1].pb(aux2);
		adj[aux2].pb(aux1);
	}
	frr(i, n){
		scanf("%d", &w[i]);
	}
	printf("%d\n", dp(1, 0)); 
}
