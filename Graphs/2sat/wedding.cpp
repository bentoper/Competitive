//UVA 11294
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
	if(i < qnt/2) return i + qnt/2;
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
	for(int i = 0; i < qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 0; i < qnt/2; i++){
		if(id[i] == id[neg(i)]) return false;
		eval[i] = id[i] < id[neg(i)];
		eval[neg(i)] = !eval[i];
	}

	return true;
}

int main(){
	int n, m;
	while(cin >> n >> m && n != 0){
		qnt = 4*n;
		fr(i, qnt){
			pre[i] = -1;
			adj[i].clear();
		}
		numSCC = 0;
		clk = 0;
		add_imp(neg(0), 0);
		fr(i, n){
			add_xor(i, i+n);
		}
		fr(i, m){
			char c; cin >> c;
			int b = 0;
			while(!(c >= '0' && c <= '9')) cin >> c;
			while(c >= '0' && c <= '9'){
				b *= 10;
				b += c - '0';
				cin >> c;
			}
			if(c == 'h') b += n;
			while(!(c >= '0' && c <= '9')) cin >> c;
			int a = 0;
			while(c >= '0' && c <= '9'){
				a *= 10;
				a += c - '0';
				cin >> c;
			}
			if(c == 'h') a += n;
			add_or(a, b);
		}
		if(sat()){
			bool first = true;
			fr(i, qnt/2){
				if(i == 0) continue;
				if(eval[i]){
					if(!first) cout << " ";
					first = false;
					if(i >= n){
						cout << i - n << "h";
					}
					else cout << i << "w";
				}
			}
			cout << "\n";
		}
		else cout << "bad luck\n";
	}
}





