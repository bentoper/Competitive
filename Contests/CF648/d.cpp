#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


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
const int N = 51;

int n, m;
char grid[N][N];

int par[N*N], depth[N*N], id[N][N];

int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	depth[y] += depth[x];

}

int val(int i, int j){
    return id[i][j];
}

bool inrange(int i, int limit){
    return (i >= 0 && i < limit);
}

int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        int gg = 0;
        int ccc = 0;
        fr(i, n){
            fr(j, m){
                cin >> grid[i][j];
                id[i][j] = ccc++;
                par[val(i, j)] = val(i, j);
                depth[val(i, j)] = 1;
            }
        }
        bool deu = true;
        if(grid[n-1][m-1] == 'B'){
            cout << "No\n";
            continue;
        }
        fr(i, n){
            fr(j, m){
                if(grid[i][j] == 'B'){
                    fr(k, 4){
                        int nx = i+xx[k], ny = j+yy[k];
                        if(inrange(nx, n) && inrange(ny, m)){
                            if(grid[nx][ny] == 'G') deu = false;
                            if(grid[nx][ny] != '.') continue;
                            grid[nx][ny] = '#';
                        }
                    }
                }
                else if(grid[i][j] == 'G'){
                    gg++;
                }
            }
        }
        if(gg == 0){
            cout << "Yes\n";
            continue;
        }
        if(!deu){
            cout << "No\n";
            continue;
        }
        fr(i, n){
            fr(j, m){
                if(grid[i][j] == '.' || grid[i][j] == 'G'){
                    fr(k, 4){
                        int nx = i + xx[k], ny = j + yy[k];
                        if(inrange(nx, n) && inrange(ny, m)){
                            if(grid[nx][ny] != 'B' && grid[nx][ny] != '#'){
                                join(val(i, j), val(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        fr(i, n){
            fr(j, m){
                if(grid[i][j] == 'G'){
                    if(find(val(i, j)) != find(val(n-1, m-1))) deu = false;
                }
            }
        }
        if(!deu){
            cout << "No\n";
        }
        else cout << "Yes\n";

    }
}
