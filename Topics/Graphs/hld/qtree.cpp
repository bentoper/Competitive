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

const int N = 1e5 + 5;
const int MAXN = 1e5 + 5;
int n;
vector <int> adj[N];
int dist[N], size[N], pai[N];
int ind, id[N], heavy[N], ch, chain[N], top[N], heavyIdx[N];


vii edges;

vi peso[N];

ll arr[N];

ll seg[4*N + 1];

int hi[4*MAXN + 1], lo[4*MAXN + 1], v[MAXN + 1];

ll update(ll a, ll b){
	return a > b ? a : b;
}

ll build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = v[start];
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 

}

ll query(int node, int start, int end){
	//printf("s %d e %d\n", start, end);

	if(hi[node] < start || lo[node] > end || start > end) return -INF;
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, int x){

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		seg[node] = x;
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}

int pre (int at) {
	size[at] = 1;

	int i = 0;

	for (auto next : adj[at]) {
		if (next == pai[at])	{i++; continue;}
		dist[next] = dist[at] + 1;
		pai[next] = at;

		size[at] += pre (next);
		
		if (size[next] > size[heavy[at]]){
			heavy[at] = next;
			heavyIdx[at] = i;
		}

		i++;
	}
	
	return size[at];
}

void dfs (int at, int pai, int cost) {
	//printf("v %d id %d\n", at, ind);
	v[ind] = cost;
	id[at] = ind++;

	if (heavy[at])	{
		chain[heavy[at]] = chain[at];
		dfs (heavy[at], at, peso[at][heavyIdx[at]]);
	}

	int i = 0;

	for (auto next : adj[at]) {
		if (next == pai or next == heavy[at]){
			i++;
			continue;
		}
		top[ch] = next;
		chain[next] = ch++;
		dfs (next, at, peso[at][i]);
		i++;
	}
}

void build_hld () {
	pre (1);
	ind = ch = 0;
	chain[1] = ch++;
	top[0] = 1;
	dfs (1, -1, -INF);
}

ll go (int u, int v) {
	//printf("idu %d idv %d\n", id[u], id[v]);
	ll res = -INF;
	while (chain[u] != chain[v]) {
		if (dist[top[chain[u]]] < dist[top[chain[v]]])	swap (u, v);

		int sobe = top[chain[u]];
		/********* ORDEM: id[sobe] < id[u] ***********/
		res = max(res, query (1, id[sobe], id[u]));
		u = pai[sobe];
	}
	if (id[u] > id[v])	swap (u, v);

	return max(res, query (1, id[u]+1, id[v]));
}

int main (void) {

	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		frr(i, n){
			peso[i].clear();
			adj[i].clear();
			dist[i] = 0;
			pai[i] = 0;
			size[i] = 0;
			heavy[i] = 0;
			heavyIdx[i] = 0;
		}
		edges.clear();
		fr(i, n-1){
			rvr(a); rvr(b);
			ll c; scanf("%lld", &c);
			a; b;
			adj[a].pb(b);
			adj[b].pb(a);
			peso[a].pb(c);
			peso[b].pb(c);
			edges.pb({a, b});
		}

		build_hld();

		build(1, 0, n-1);

		while(true){
			char s[100];
			scanf("%s", s);
			if(s[0] == 'D') break;
			rvr(a); rvr(b);
			if(s[0] == 'Q'){
				if(a == b) printf("0\n");
				else printf("%lld\n", go(a, b));
			}
			else{
				a--;
				int aa = edges[a].first;
				int bb = edges[a].second; 
				if(dist[aa] < dist[bb]) swap(aa, bb);
				change(1, id[aa], id[aa], b);
			}
		}
	}
}