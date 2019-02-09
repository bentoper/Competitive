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
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int dist[333], N = 1, R = 1;


struct edge{
	int a;
	int b;
	int w;
};

void solve(){
	vector<edge> edges;
	ms(dist, -INF);
	for(int i = 0; i < R; i++){
		int ori, des, peso;
		cin >> ori >> des >> peso;
		edges
	}
	int S, D, T;
	cin >> S >> D >> T;
	dist[S] = INF;
	fr(i, N-1){
		for(auto e: edges){
			dist[e.b] = max(dist[e.b], min(dist[e.a], e.w))
		}		
	}
	dist[D]--;
	if(T%dist[D] == 0) T += dist[D];
}

int main(){
	fastio;
	
	while(cin >> N >> R && N != 0 && R != 0){
		solve();
		
	}
}
