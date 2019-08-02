//UVA 10092
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
#define MAXN 5123
#define MAXM 312345

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int to[MAXM], nxt[MAXM];

ll cap[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
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
	
	int nk, np;
	while(scanf("%d%d", &nk, &np) && nk != 0){
		init();
		ll sum = 0;
		frr(i, nk){
			int a; scanf("%d", &a);
			add(np+i, np+nk+1, a);
			sum += a;
		}
		frr(i, np){
			add(0, i, 1);
			int a; scanf("%d", &a);
			fr(j, a){
				int b; scanf("%d", &b);
				add(i, b+np, 1);
			}
		}

		if(dinic(0, np+nk+1) == sum){
			printf("1\n");
			vi ans[nk];
			frr(i, np){
				for(int e = first[i]; e != -1; e = nxt[e]){
					if(e&1) continue;
					if(cap[e] == 0) {ans[to[e] - np - 1].pb(i); break;}
				}
			}
			fr(i, nk){
				int sz = ans[i].size();
				for(int j = 0; j < sz; j++){
					printf("%d", ans[i][j]);
					if(j != sz - 1) printf(" ");
				}
				printf("\n");
			}
		}
		else printf("0\n");
	}

}








