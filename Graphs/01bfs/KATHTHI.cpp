#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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
const int N = 1e3 +1;


int dist[N][N];
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

char grid[N][N];
int R, C;

pii dest;



int bfs(){
    
    deque<pair<int,int>> dq;
    dq.push_front(mp(0, 0));
    dist[0][0] = 0;
    while(!dq.empty()){
        pii v = dq[0];
        dq.pop_front();
        int vx = v.first, vy = v.second;
        if(v == dest) return dist[vx][vy];
        fr(i, 4){
            int xx = vx + x[i], yy = vy + y[i]; 
            //printf("%d %d %d\n", xx, yy, dist[xx][yy]);
            if(xx >= 0 && xx < R && yy >= 0 && yy < C){
                int eq = (grid[vx][vy] != grid[xx][yy]);
                int rlx = dist[vx][vy] + eq;
                if(dist[xx][yy] > rlx){
                    dist[xx][yy] = rlx;
                    if(eq){
                        dq.push_back(mp(xx, yy));
                    }
                    else dq.push_front(mp(xx, yy));
                }
            }
        }
    }
    return 0;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &R, &C);
        fr(i, R){
            fr(j, C){
                do{
                    scanf("%c", &grid[i][j]);
                    //printf("%c\n", grid[i][j]);
                }while(grid[i][j] < 'a' || grid[i][j] > 'z');
                dist[i][j] = INF;
            }
        }
        dest = mp(R-1, C-1);
        printf("%d\n", bfs());
    }
}
