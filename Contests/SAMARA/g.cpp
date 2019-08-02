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
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 112345

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vii v;

int vis[MAXN], n, q;

map<pii, int> id;

vii edges[MAXN];

void dfs(int i, pii mx){
	
	vis[i] = 1;

	int plc = INF;
	
	sort(all(edges[i]));

	int qnt = edges[i].size(); 

	for(int j = qnt - 1; j >= 0; j--){
		pii e = edges[i][j];
		swap(e.first, e.second);
		if(vis[e.first]) continue;
		if(e.second < mx.second) dfs(e.first, mp(e.snd + 1, mx.snd));
		else if(j == 0){
			v.pb(mx);
			id[mx] = i;
		}
		mx.snd = min(mx.snd, e.snd);
	}

	if(mx.snd >= mx.first){
		v.pb(mx);
		id[mx] = i;
	} 	
}



int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &q);
		frr(i, n) edges[i].clear();
		frr(i, n-1){
			vis[i] = 0;
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edges[u].pb({w, v});
			edges[v].pb({w, u});

		}

		vis[n] = 0;

		dfs(1, mp(1, INF));
		sort(all(v));
		ll ans = 0;
		int vaca = v.size();
		fr(i, q){
			int x; scanf("%d", &x);
			int pos = lower_bound(all(v), mp(x, 0))-v.begin();
			if(pos == vaca) pos--;
			if(v[pos].first > x) pos--;
				
			ll retards = id[v[pos]];

			ans += retards;
		}

		printf("%lld\n", ans);
		v.clear();
		id.clear();
	}
}












