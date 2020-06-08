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
const int N = 1e3 + 1;

int grid[N][N], vis[N][N];
int n, m;

void dfs(int i, int j){
    vis[i][j] = 1;
    for(int x = -1; x <= 1; x += 2){
        if(i + x >= 0 && i + x < n && vis[i+x][j] == 0 && grid[i+x][j]) dfs(i+x, j);
    }
    for(int x = -1; x <= 1; x += 2){
        if(j + x >= 0 && j + x < m && vis[i][j+x] == 0 && grid[i][j+x]) dfs(i, j+x);
    }
}


int main(){
    fastio;
    cin >> n >> m;
    char c;
    fr(i, n){
        fr(j, m){
            cin >> c;
            grid[i][j] = (c=='#');
        }
    }
    bool deu = true;
    int cnt = 0, cnt2 = 0;
    fr(i, n){
        int found = false, cant = false;
        fr(j, m){
            if(grid[i][j] && cant){
                deu = false;
                goto END;
            }
            if(grid[i][j]) found = true;
            if(!grid[i][j] && found) cant = true;
        }
        if(!found) cnt = 1;
    }
    fr(j, m){
        int found = false, cant = false;
        fr(i, n){
            if(grid[i][j] && cant){
                deu = false;
                goto END;
            }
            if(grid[i][j]) found = true;
            if(!grid[i][j] && found) cant = true;
        }
        if(!found) cnt2 = 1;
    }
    END:;
    if(!deu || (cnt^cnt2)){
        cout << -1 << endl;
        return 0;
    }
    int comp = 0;
    fr(i, n){
        fr(j, m){
            if(grid[i][j] && !vis[i][j]) dfs(i, j), comp++;
        }
    }
    cout << comp << endl;
}
