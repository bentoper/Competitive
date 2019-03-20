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

int grid[1002][1002], cross, clk;

int main(){
	rvr(t);
	while(t--){
		rvr(n); rvr(m);
		cross = 0;
		frr(i, n){
			frr(j, m) scanf("%d", &grid[i][j]);
		}
		frr(i, n){
			frr(j, m){
				int curr = grid[i][j];
				int sz = 0;
				int a = i - 1, b = i + 1, c = j - 1, d = j + 1;
				while(a >= 1 && grid[a][j] == curr){a--;}
				while(b <= n && grid[b][j] == curr){b++;}
				while(c >= 1 && grid[i][c] == curr){c--;}
				while(d <= m && grid[i][d] == curr){d++;}
				if(b != i + 1 && a != i - 1 && c != j - 1 && d != j + 1) {
					cross = max(cross, (b - 1)  - (a + 1) + (d - 1) - (c + 1) + 1);
				}
			}
		}
		printf("Case %d: %d\n", ++clk, cross);
	}
}
