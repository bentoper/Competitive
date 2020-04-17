//https://www.spoj.com/problems/DISJPATH/
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
#define MAXN 11234
#define MAXM 51234567

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

ll clk = 0;

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

void dfsprint(int u, int t){
	if(u == t) {printf("2\n"); return;}
	for(int e = first[u]; e != -1; e = nxt[e]) {
		if(e&1) continue;
		int v = to[e];
		if(cap[e] == 0){
			if(u&1) printf("%d ", u/2);
			dfsprint(v, t);
			if(u != 3) return;
		}
	}
}

int main() {
	int n, m;
	bool first = true;
	while(scanf("%d%d", &n, &m) && n != 0){
		if(!first) printf("\n");
		first = false;
		init();
		fr(i, m){
			int a = i + 1;
			if(a > 2) add(2*a, 2*a+1, 1);
			else add(2*a, 2*a+1, n);
			char c = '\n';
			while(!(c >= '0' && c <= '9')) scanf("%c", &c); 
			while(c != '\n'){
				int b = 0;
				while(c >= '0' && c <= '9'){
					b *= 10;
					b += (int)(c - '0');
					scanf("%c", &c);
				}
				add(2*a + 1, 2*b, 1);
				if(c == '\n') break;
				scanf("%c", &c);
			}
		}
		ll ans = dinic(2, 5);
		printf("Case %lld:\n", ++clk);
		if(ans < n){
			printf("Impossible\n");
			continue;
		}
		dfsprint(2, 4);
	}
}