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
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n, a[101], memo[101][101][2][2];

int dp(int i, int rest, int s, int c){
	if(i == n) return 0;
	int &pdm = memo[i][rest][s][c];
	if(pdm == -1){
		pdm = INF;
		if(s != 1 && a[i] >= 2){
			pdm = min(pdm, dp(i+1, rest, 1, 0));
		}
		if(c != 1 && (a[i] == 1 || a[i] == 3)){
			pdm = min(pdm, dp(i+1, rest, 0, 1));
		}
		pdm = min(pdm, dp(i+1, rest+1, 0, 0) + 1);
	}
	return pdm;
}



int main(){
	scanf("%d", &n);
	fr(i, n) scanf("%d", &a[i]);
	ms(memo, -1);
	printf("%d\n", dp(0, 0, 0, 0));
}
