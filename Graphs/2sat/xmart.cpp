//https://codeforces.com/contest/776/problem/D
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

#define MAXN 412345 //twice amount of stuff

ll clk = 0, qnt = 0;

int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

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
        else low[v] = min(low[v], low[x]);
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

void force_var(int i){
	add_imp(neg(i), i);
}

void add_iff(int i, int j){
	add_imp(i, j);
	add_imp(neg(i), neg(j));
	add_imp(j, i);
	add_imp(neg(j), neg(i));
}

bool sat(){
	for(int i = 1; i <= qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 1; i <= qnt/2; i++){
		if(id[i] == id[neg(i)]) return false;
	}

	return true;

}

void init(int sz){
	qnt = 2*sz;
	clk = 0;
	numSCC = 0;
	frr(i, qnt){
		adj[i].clear();
		pre[i] = -1;
	}
}

int main(){
	int n, m;
	while(scanf("%d%d", &m, &n) && n != 0){
		init(n);
		fr(i, m){
			int x, y, s, t;
			scanf("%d%d%d%d", &x, &y, &s, &t);
			if(x != 0 && y != 0){
				add_or(x, y);
			}
			else if(x == 0 && y != 0) force_var(y);
			else if(y == 0 && x != 0) force_var(x);
			
			if(s != 0 && t != 0) add_or(neg(s), neg(t));
			else if(s == 0 && t != 0) force_var(neg(t));
			else if(s != 0 && t == 0) force_var(neg(s));
			
		}
		if(sat()){
			printf("yes\n");
		}
		else printf("no\n");
	}
    
}