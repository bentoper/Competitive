//https://codeforces.com/contest/321/problem/C
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

#define MAXN 212345

int clevel[MAXN], cpar[MAXN], sz[MAXN], dist[MAXN];
vector<int> centree[MAXN];
vector<int> adj[MAXN];
int n, m;

char ans[MAXN];

int subsize(int v, int p) {
	sz[v]=1;
	for(auto x: adj[v]) {
		if(x == p || clevel[x] != -1) continue;
		sz[v] += subsize(x, v);
	}
	return sz[v];
}

int findcentroid(int v, int p, int nn) {
	for(auto x: adj[v]) {
		if (x != p && clevel[x] < 0 && sz[x] > nn/2){
			return findcentroid(x, v, nn);
		}
	}
	return v;
}

int decompose(int root, int par, char curr) {
	subsize(root, -1);
	int u = findcentroid(root, -1, sz[root]);
	cpar[u] = par;
	clevel[u] = par >= 0 ? clevel[par]+1 : 0;
	sz[u] = 1;
	ans[u] = curr;
	for(auto v: adj[u]) {
		if (v != par && clevel[v] < 0) {
			v = decompose(v, u, (char) curr + 1);
			centree[u].push_back(v);
			sz[u] += sz[v];
		}
	}
	return u;
}

int centroiddecomposition(int root) {
	for(int i = 1; i <= n; i++){
		sz[i] = 0;
		clevel[i] = -1;
		centree[i].clear();
	}
	return decompose(root, -1, 'A');
}


int main(){
	cin >> n;
	fr(i, n-1){
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	centroiddecomposition(1);

	frr(i, n){
		cout << ans[i] << " \n"[i == n];
	}


}
