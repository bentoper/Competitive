//https://codeforces.com/problemset/problem/546/E
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
#define MAXN 212
#define MAXM 11234567

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

int a[112], b[112];

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
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	ll sum = 0, cpsum;
	frr(i, n){
		scanf("%d", &a[i]);
		sum += a[i];
		add(0, 2*i, a[i]);
	}
	cpsum = sum;
	frr(i, n) {
		scanf("%d", &b[i]);
		cpsum -= b[i];
		add(2*i+1, 2*(n+1), b[i]);
		add(2*i, 2*i+1, b[i]);
	}
	fr(i, m){
		int p, q; scanf("%d%d", &p, &q);
		add(2*p, 2*q+1, b[q]);
		swap(p, q);
		add(2*p, 2*q+1, b[q]);
	}
	if(cpsum != 0){
		printf("NO\n");
		return 0;
	}
	if(dinic(0, 2*n+2) == sum){
		printf("YES\n");
		int matrix[n][n];
		ms(matrix, 0);
		for(int i = 2; i < 2*n + 2; i += 2){
			for(int e = first[i]; e != -1; e = nxt[e]){
				if(e&1) continue;
				if(b[to[e]/2] - cap[e] != 0){
					matrix[i/2 - 1][to[e]/2 - 1] = b[to[e]/2] - cap[e];  
				}
			}
		}
		fr(i, n){
			fr(j, n){
				printf("%d", matrix[i][j]);
				if(j != n-1) printf(" ");
			}
			printf("\n");
		}
	}
	else{
		printf("NO\n");
		return 0;
	}
}