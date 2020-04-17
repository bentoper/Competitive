//https://www.spoj.com/problems/BUGLIFE/
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

#define MAXN 112345 //twice amount of stuff

ll clk = 0, qnt = 0;

int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

bool eval[MAXN];

vector<int> adj[MAXN];

stack<int> nodes;

void dfs(int v){

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];

	for(auto x: adj[v]){
		if(pre[x] == -1){
			dfs(x);
			low[v] = min(low[v], low[x]);
		}
		else low[v] = min(low[v], pre[x]);
	}

	if(low[v] == pre[v]){
		while(true){
			int j = nodes.top();
			nodes.pop();
			id[j] = numSCC;
			low[j] = MAXN;
			if(j == v) break;
		}
		numSCC++;
	}

}

int neg(int i){
	if(i <= qnt/2) return i + qnt/2;
	return i - qnt/2; 
}


void add_imp(int i, int j){
	adj[i].pb(j);
}

void add_or(int i, int j){
	add_imp(neg(i), j);
	add_imp(neg(j), i);
}

void add_xor(int i, int j){
	add_or(i, j);
	add_or(neg(i), neg(j));
}

bool sat(){
	for(int i = 1; i <= qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 1; i <= qnt/2; i++){
		if(id[i] == id[neg(i)]) return false;
		eval[i] = id[i] > id[neg(i)];
		eval[neg(i)] = !eval[i];
	}

	return true;
}

int main(){
	int t; scanf("%d", &t);
	frr(cs, t){
		int n, m; scanf("%d%d", &n, &m);
		qnt = 2*n;
		frr(i, qnt){
			pre[i] = -1;
			id[i] = 0;
			numSCC = 0;
			clk = 0;
			eval[i] = false;
			adj[i].clear();
		}

		fr(i, m){
			int a, b; scanf("%d%d", &a, &b);
			add_xor(a, b);
		}

		printf("Scenario #%d:\n", cs);

		if(sat()){
			printf("No suspicious bugs found!\n");
		}
		else{
			printf("Suspicious bugs found!\n");
		}
	}
}









