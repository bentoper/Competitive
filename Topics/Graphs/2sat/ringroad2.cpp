//https://codeforces.com/problemset/problem/27/D//
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

map<pii, int> ide; 

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
		}
		low[v] = min(low[v], low[x]);
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
		eval[i] = id[i] < id[neg(i)];
		eval[neg(i)] = !eval[i];
	}

	return true;
}

void init(){
	frr(i, 2*qnt){
		pre[i] = -1;
	}
	numSCC = 0;
	clk = 0;
}

int main(){
	int n, m;
	vii v;
	scanf("%d%d", &n, &m);
	int counter = 1;
	fr(i, m){
		int a, b; scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		pii plc = mp(a, b);
		v.pb(plc);
		ide[plc] = counter++;
	}
	qnt = 2*m;
	frr(i, qnt){
		pre[i] = -1;
	}
	sort(all(v));
	fr(i, m){
		int a = v[i].first, b = v[i].second;
		fr(j, m){
			if(j == i) continue;
			if(v[j].first > a && v[j].first < b){
				if(v[j].second > b) add_xor(ide[v[i]], ide[v[j]]);
			}
			if(v[j].second > a && v[j].second < b){
				if(v[j].first < a) add_xor(ide[v[i]], ide[v[j]]);
			}
		}
	}
	if(sat()){
		frr(i, qnt/2){
			if(eval[i]){
				cout << 'i';
			}
			else cout << 'o';
		}
		cout << "\n";
	}
	else cout << "Impossible\n";
}
