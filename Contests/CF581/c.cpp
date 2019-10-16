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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi adj[111];
vi path;


vi base;
int n, dist[111][111];

int memo[1000000];

int nextor[1000000];

int precomp[1000000][100];

void bfs(int v){
	dist[v][v] = 0;

	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int pai = q.front();
		q.pop();
		for(auto u: adj[pai]){
			if(dist[u][v] != -1) continue;
			dist[u][v] = dist[pai][v] + 1;
			q.push(u);
		}
	}
}


int dp(int i, int sz){

	if(i == sz-1) return 1;

	if(memo[i] == -1){
		memo[i] = INF;
		for(int j = 1; j <= n;j++){
			if(j == path[i]){
				continue;
			}
			int pos = precomp[i][j-1];
			if(pos == -1) continue;
			if(pos - i == dist[j][path[i]]){
				int plc = 1 + dp(pos, sz);
				if(plc < memo[i]){
					memo[i] = plc;
					nextor[i] = pos; 
				}
				
			}
		}	
	}

	return memo[i];
}

int main(){
	cin >> n;
	frr(i, n){
		frr(j, n){
			char c; cin >> c;
			if(c == '1'){
				adj[i].pb(j);
			}
			dist[i][j] = -1;
		}
	}
	int sz; cin >> sz;
	int frst, last;
	
	fr(i, sz){
		int c; cin >> c;
		
		if(i == 0) frst = c;
		if(i == sz-1) last = c;
		path.pb(c);
		memo[i] = -1;
	}

	for(int i = sz-1; i >= 0; i--){
		frr(j, 100){
			if(i == sz - 1) precomp[i][j-1] = -1; 
			else precomp[i][j-1] = precomp[i+1][j-1]; 
		}
		precomp[i][path[i] - 1] = i;
	}

	frr(i, n) bfs(i);


	base.pb(path[sz-1]);
	cout << dp(0, sz) << endl;
	nextor[sz-1] = -1;


	int nxt = 0;
	bool first = true;
	while(nxt != -1){
		if(!first) cout << " ";
		first = false;
		cout << path[nxt];
		nxt = nextor[nxt];
	}

	cout << endl;


}






