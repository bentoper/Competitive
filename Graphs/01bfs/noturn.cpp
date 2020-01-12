#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
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
const int N = 501;

int maze[N][N], dist[N][N][4];

int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};

struct state{
    int x;
    int y;
    int dir;
};


void bfs(int N){
    deque<state> dq;
    fr(k, 4) dist[0][0][k] = 0, dq.push_front({0, 0, k});
    while(!dq.empty()){
        int x = dq.front().x;
        int y = dq.front().y;
        int dir = dq.front().dir;
        dq.pop_front();
        fr(k, 4){
            int nx = x + xx[k], ny = y + yy[k];
            if(!(nx >= 0 && nx < N) || !(ny >= 0 && ny < N)) continue;
            if(maze[nx][ny]) continue;
            int diff = 0;
            if(dir != k) diff = 1;
            if(dist[x][y][dir] + diff < dist[nx][ny][k]){
                dist[nx][ny][k] = (dist[x][y][dir] + diff);
                if(diff == 0) dq.push_front({nx, ny, k});
                else dq.push_back({nx, ny, k});
            }
        }
    }    
}


class DoNotTurn{
    
    public:
    
    int minimumTurns(int N, int X0, int A, int B, int Y0, int C, int D, int P, int M){
        ll X = X0%P, Y = Y0%P;
        fr(i, M){
            int x = X%(ll)N, y = Y%(ll)N;
            if(!((x == 0 && y == 0) || (x == N-1 && y == N-1))) maze[x][y] = 1;
            X = ((X*(ll)A)%P + (ll)B)%P;
            Y = ((Y*(ll)C)%P + (ll)D)%P;
        }

        fr(i, N){
            fr(j, N){
                fr(k, 4) dist[i][j][k] = INF;
            }
        }
        
        bfs(N);
        int mindist = INF;
        fr(i, 4){
            mindist = min(mindist, dist[N-1][N-1][i]);
        }
        return (mindist==INF?-1:mindist);
    }

};

int main(){
    int arg[9];
    fr(i, 9) scanf("%d", &arg[i]);
    DoNotTurn t;
    printf("%d\n", t.minimumTurns(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8]));

}
