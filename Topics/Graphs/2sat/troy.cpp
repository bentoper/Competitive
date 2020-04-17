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
#define N 212345


int q;

ll clk = 0, qnt = 0;

int vrtx = 0;


int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

vector<int> adj[MAXN];

stack<int> nodes;

map<ll, int> mcol, mrow;


int a[N], b[N], tp[N];

//tp[i] = 0 XOR tp[i] = 1 IFF

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

void  add_iff(int i, int j){
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

int main(){
	scanf("%d", &q);
	frr(i, q){
		ll aa, bb;
		int x, y;
		scanf("%lld%lld%d%d", &aa, &bb, &x, &y);
		if(mrow[aa] == 0) mrow[aa] = ++vrtx;
		if(mcol[bb] == 0) mcol[bb] = ++vrtx;
		a[i] = mrow[aa];
		b[i] = mcol[bb];
		if(x == y) tp[i] = 1;
		else tp[i] = 0;
	}
	qnt = 2*vrtx;

	int l = 1, r = q;
	while(l <= r){
		numSCC = 0;
		frr(i, qnt) {
			adj[i].clear();
			pre[i] = -1;
		}
		int mid = (r - l)/2 + l;
		//printf("l = %d r %d m %d\n", l, r, mid);
		frr(i, mid){
			if(tp[i]){
				add_iff(a[i], b[i]);
			}
			else add_xor(a[i], b[i]);
		}
		if(sat()) l = mid + 1;
		else r = mid - 1;
	}
	//printf("l = %d r = %d\n", l, r);
	frr(i, q){
		if(i <= min(l, r)) printf("Yes\n");
		else printf("No\n");
	}
	
}
