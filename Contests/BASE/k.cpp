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

#define MAXN 3000
#define MAXM 123456

using namespace std;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

char grid[33][33];

int m, n;

int posx[] = {1, 0, -1, 0};
int posy[] = {0, 1, 0, -1};

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

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
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

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

int main(){
	char c = 1;

	while(c > 0){

		init();

		int x = 0, y = 0;

		c = getchar();		

		while(true){
			grid[x][y] = c;
			y++;
			c = getchar();
			if(!(c == 'W' || c == 'I' || c == 'N')){
				c = getchar();
				x++;
				n = y;
				y = 0;
				if(!(c == 'W' || c == 'I' || c == 'N')){
					break;	
				}
			}
		}

		//printf("c = %d\n", c);

		m = x;

		fr(i, m){
			fr(j, n){
				if(grid[i][j] == 'W'){
					add(n*m, i*m + j, 1);
					fr(k, 4){
						int ni = i + posx[k], nj = j + posy[k];
						if(ni < m && ni >= 0 && nj < n && nj >= 0){
							if(grid[ni][nj] == 'I'){
								add(i*m+j, ni*m + nj, 1);
							}
						}
					}
				}
				else if(grid[i][j] == 'I'){
					fr(k, 4){
						int ni = i + posx[k], nj = j + posy[k];
						if(ni < m && ni >= 0 && nj < n && nj >= 0){
							if(grid[ni][nj] == 'N'){
								add(i*m+j, ni*m + nj, 1);
							}
						}
					}
				}
				else if(grid[i][j] == 'N') add(i*m + j, (n*m)+1, 1);
			}
		}

		printf("%d\n", dinic(n*m, n*m+1));

	}
}