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

int n, m, q;
int grid[N][N];
vector<pair<pii, pii>> queries;

int I[] = {1, 0, -1, 0};
int J[] = {0, -1, 0, 1};

int par[N*N], depth[N*N];

int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;

}

int id(int x, int y){
    x--;
    y--;
    return x*m + y + 1; 
}

bool valid(int x, int y){
    return(x > 0 && x <= n && y > 0 && y <= m && grid[x][y] == 0);
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    fr(i, q){
        rvr(a); rvr(b); rvr(x); rvr(y);
        queries.pb(mp(mp(a, b), mp(x, y)));
        for(int xx = a; xx <= x; xx++){
            for(int yy = b; yy <= y; yy++) grid[xx][yy]++;
        }
    }
    frr(i, n*m){
        par[i] = i;
    }
    int comp = n*m;
    frr(i, n){
        frr(j, m){
            if(grid[i][j] >= 1){
                comp--;
                continue;
            }
            fr(k, 4){
                int nx = i + I[k], ny = j + J[k];
                if(valid(nx, ny) && find(id(i, j)) != find(id(nx, ny))){
                    comp--;
                    join(find(id(i, j)), find(id(nx, ny)));
                }
            }
        }
    }
    stack<int> stk;
    for(int i = q - 1; i >= 0; i--){
        stk.push(comp);
        for(int x = queries[i].first.first; x <= queries[i].second.first; x++){
            for(int y = queries[i].first.second; y <= queries[i].second.second; y++){
                grid[x][y]--;
                if(grid[x][y] > 0) continue;
                comp++;
                fr(k, 4){
                    int nx = x + I[k], ny = y + J[k];
                    if(valid(nx, ny) && find(id(x, y)) != find(id(nx, ny))){
                        join(id(x, y), id(nx, ny));
                        comp--;
                    }
                }
            }    
        }
    }
    while(!stk.empty()){
        printf("%d\n", stk.top());
        stk.pop();
    }
}
