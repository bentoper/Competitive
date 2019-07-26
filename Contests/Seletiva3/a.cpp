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

map<string, int> m;
vector<string> names;
int dist[1123];
vi adj[1123];

int isan = 0;

void bfs(){
	int clk = 0;
	dist[isan] = 0;
	vi q;
	q.pb(isan);
	while(clk < q.size()){
		int v = q[clk++];
		for(auto x: adj[v]){
			if(dist[x] == -1){
				dist[x] = dist[v] + 1;
				q.pb(x);
			}
		}
	}
}

int main(){
	int n; cin >> n;
	int cnt = 1;
	string I = "Isenbaev";
	ms(dist, -1);
	fr(i, n){
		string s[3];
		vi plc;
		fr(j, 3){
			cin >> s[j];
			if(m[s[j]] == 0){
				m[s[j]] = cnt++;
				names.pb(s[j]);
				if(s[j] == I) isan = cnt - 1;
			}
			plc.pb(m[s[j]]);
		}
		for(auto x: plc){
			for(auto z: plc){
				if(x != z){
					adj[x].pb(z);
				}
			}
		}
	}
	bfs();
	sort(all(names));
	for(string x: names){
		cout << x << " ";
		if(dist[m[x]] == -1){
			cout << "undefined" << endl;
		}
		else cout << dist[m[x]] << endl;
	}
}




















