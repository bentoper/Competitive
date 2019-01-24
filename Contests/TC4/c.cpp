#include "bits/stdc++.h"
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
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int x[3], y[3], clear[1001][1001], cost[1001][1001];
int dirx[] = {0, 1, 0, -1};
int diry[] = {-1, 0, 1, 0};

int bfs(int x, int y, int prx, int pry){
	dbg(x); dbg(y);
	if(x == prx && y == pry){
		cost[x][y] = 1;
		return 1;
	}
	fr(i, 4){
		int nx = x + dirx[i];
		int ny = y + diry[i];
		if(nx < 0 || nx > 1000 || ny < 0 || ny > 1000) continue;
		if(cost[nx][ny] < INF) continue;
		if(bfs(nx, ny, prx, pry) == 1){
			clear[nx][ny] = 1;
			cost[x][y] = 1 + cost[nx][ny];
			return 1;
		}
		else{
			cost[nx][ny] = cost[x][y] + 1;
		}
	}
	return 0;
}



int main(){
	fr(i, 3){
		scanf("%d%d", &x[i], &y[i]);
	}
	fr(i, 1001){
		fr(j, 1001) cost[i][j] = INF;
	}
	cost[x[0]][y[0]] = 0;
	clear[x[0]][y[0]] = 1;
	bfs(x[0], y[0], x[1], y[1]);
	printf("custo %d\n", cost[x[0]][y[0]]);
}
