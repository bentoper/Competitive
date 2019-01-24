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
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n, visited[101], cnt = -1;
vi x[1001], y[1001], adj[101];

void dfs(int root){
	if(visited[root]) return;
	visited[root] = 1;
	for(auto z: adj[root]){
		if(visited[z]) continue;
		dfs(z);
	}
}


int main(){
	scanf("%d", &n);
	fr(i, n){
		rvr(aux1); rvr(aux2);
		for(auto z: x[aux1]){
			adj[i].pb(z);
			adj[z].pb(i);
		}
		for(auto z: y[aux2]){
			adj[i].pb(z);
			adj[z].pb(i);
		}
		x[aux1].pb(i);
		y[aux2].pb(i);
	}
	fr(i, n){
		if(visited[i]) continue;
		dfs(i);
		cnt++;
	}
	printf("%d\n", cnt);

}
