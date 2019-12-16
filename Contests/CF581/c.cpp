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
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 111;

vi adj[N];
int n, dist[N][N];


void bfs(int r){
	dist[r][r] = 0;
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: adj[u]){
			if(dist[r][v] > dist[r][u] + 1){
				dist[r][v] = dist[r][u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	frr(i, n){
		frr(j, n){
			char a;
			do{
				scanf("%c", &a);
			}while(a != '1' && a != '0');
			if(a == '1') adj[i].pb(j); 
			dist[i][j] = INF;
		}
	}

	frr(i, n) bfs(i);

	int spth; scanf("%d", &spth);
	vi path;

	fr(i, spth){
		int a; scanf("%d", &a); path.pb(a);
	} 

	vi ans;
	int i = 0, j = 0;
	ans.pb(path[0]);
	while(j < spth){
		while(j < spth && dist[path[i]][path[j]] == j - i) j++;
		j--;
		ans.pb(path[j]);
		i = j;
		j = i+1;
	}
	printf("%d\n", (int)ans.size());
	pv(ans, ans.size());
}



