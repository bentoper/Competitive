//UVA 10480
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
#define MAXN 60
#define MAXM 2123

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN], from[MAXM];
int to[MAXM], nxt[MAXM];

ll cap[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, ll f) {
	from[ned] = u;
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	from[ned] = v;
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

ll dfs(int u, ll f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			ll df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

ll dinic(int s, int t) {
	ll result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) && n != 0){
		init();
		fr(i, m){
			int a, b; scanf("%d%d", &a, &b);
			ll c; scanf("%lld", &c);
			add(a, b, c);
			swap(a, b);
			add(a, b, c);
		}
		dinic(1, 2);
		for(int i = 0; i < ned; i+=2){
			if(cap[i] == 0){
				if(from[i] == 1 && dist[to[i]] == -1) printf("%d %d\n", from[i], to[i]);
				else if(to[i] == 1 && dist[from[i]] == -1) printf("%d %d\n", from[i], to[i]);
				else if(dist[to[i]]*dist[from[i]] < 0) printf("%d %d\n", from[i], to[i]);
				
			}
		}
		printf("\n");
	}
}