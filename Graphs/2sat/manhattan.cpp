//UVA 10319
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

int main(){
	int t; cin >> t;
	while(t--){
		int s, a, m;
		cin >> s >> a >> m;
		qnt = (s+a)*2;
		clk = 0;
		numSCC = 0;
		frr(i, qnt) {adj[i].clear(); pre[i] = -1;}
		fr(i, m){
			int s1, a1, s2, a2;
			cin >> s1 >> a1 >> s2 >> a2;
			if(a1 == a2 && s2 > s1) force_var(a1 + s);
			else if(a1 == a2 && s2 < s1) force_var(neg(a1+s));
			else if(s1 == s2 && a2 > a1) force_var(s1);
			else if(s1 == s2 && a2 < a1) force_var(neg(s1));
			else if(a1 > a2 && s2 > s1){
				add_or(a1 + s, neg(s1));
				add_or(s + a1, s + a2);
				add_or(neg(s1), neg(s2));
				add_or(neg(s2), a1 + s);
			}
			else if(a2 > a1 && s2 > s1){
				add_or(a1 + s, s1);
				add_or(s + a1, s + a2);
				add_or(s1, s2);
				add_or(s2, a1 + s);
			}
			else if(a1 > a2 && s1 > s2){
				add_or(neg(a1 + s), neg(s1));
				add_or(neg(s + a1), neg(s + a2));
				add_or(neg(s1), neg(s2));
				add_or(neg(s2), neg(a1 + s));
			}
			else if(a2 > a1 && s1 > s2){
				add_or(neg(a1 + s), s1);
				add_or(neg(s + a1), neg(s + a2));
				add_or(s1, s2);
				add_or(s2, neg(a1 + s));
			}

		}
		if(sat()){
			cout << "Yes\n";
		}
		else cout << "No\n";
	}

}
