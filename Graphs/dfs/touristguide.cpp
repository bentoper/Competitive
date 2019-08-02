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
#define MAXN 1123

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll low[MAXN], pre[MAXN], n, m;

ll qnt = 0, clk = 0, caso = 0;

string name[MAXN];

bool art[MAXN];
vector<string> ans;

struct Edges{
	int x, y;
	ll idx;
};

vector<Edges> edges[MAXN];

map<string, int> id;


void dfs(int v, int p, ll idx){

	pre[v] = clk++;
	low[v] = pre[v];

	bool forw = false;
	for(auto e: edges[v]){
		int x = e.y;
		if(e.idx == idx) continue;
		if(pre[x] == -1){
			dfs(x, v, e.idx);
			low[v] = min(low[v], low[x]);
			if(v != p ? low[x] >= pre[v] : forw){
				if(!art[v]) ans.pb(name[v]);
				art[v] = true;
			}
			forw = true;
		}
		else low[v] = min(low[v], pre[x]);
	}
}

int main(){
	fastio;
	cin >> n;
	int vaca = 0;
	while(n != 0){
		qnt = 0, clk = 0;
		ans.clear();
		if(vaca) cout << endl;
		vaca = 1;
		frr(i, n){
			string s; cin >> s;
			id[s] = i;
			name[i] = s;
			pre[i] = -1;
			art[i] = false;
			edges[i].clear();
		}
		cin >> m;
		fr(i, m){
			string a, b;
			cin >> a >> b;
			int ida = id[a], volta = id[b];
			edges[ida].pb({ida, volta, qnt});
			swap(ida, volta);
			edges[ida].pb({ida, volta, qnt++});

		}

		frr(i, n){
			if(pre[i] == -1) dfs(i, i, -1);
		}

		cout << "City map #" << ++caso << ": " << ans.size() << " camera(s) found" << endl;
		if(ans.size() != 0){
			sort(all(ans));
			for(auto x: ans){
				cout << x << endl;
			}
		}
		cin >> n;
		id.clear();
	}

}
