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

int n, x, k;
ll w[200], memo[200][200][200];


ll dp(int i, int gt, int tgt){
	if(gt == x && i == n && tgt < k) return 0;
	if(tgt == k || gt > x || i == n) return -llINF;
	if(memo[i][gt][tgt] == -1){
		memo[i][gt][tgt] = max(w[i] + dp(i+1, gt+1, 0), dp(i+1, gt, tgt+1));
	}
	return memo[i][gt][tgt];
}

int main(){
	scanf("%d%d%d", &n, &k, &x);
	fr(i, n){
		scanf("%lld", &w[i]);
	}
	fr(i, n){
		fr(j, n){
			fr(l, n) memo[i][j][l] = -1;
		}
	}
	ll out = dp(0, 0, 0);
	if(out < 0) printf("-1\n");
	else printf("%lld\n", out);
}
