#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)


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

void printg(vector<vector<char>>& gg, int n){
    fr(i, n){
        fr(j, n) printf("%c", gg[i][j]);
        printf("\n");
    }
}

int main(){
    tsts(t){
        rvr(n);
        vector<vector<char>> grid(n, vector<char>(n));
        fr(i, n){
            fr(j, n){
                char c = 'D';
                while(c != 'S' && c != '0' && c != '1' && c != 'F') scanf("%c", &c);
                grid[i][j] = c;
            }
        }
        if(grid[0][1] == grid[1][0]){
            if(grid[n-2][n-1] == grid[n-1][n-2] && grid[1][0] != grid[n-1][n-2]){
                printf("0\n");
            }
            else if(grid[n-2][n-1] == grid[n-1][n-2]){
                printf("2\n");
                grid[n-2][n-1] ^= 1;
                grid[n-1][n-2] ^= 1;
                printf("%d %d\n", n - 1, n);
                printf("%d %d\n", n, n - 1);
            }
            else{
                printf("1\n");
                if(grid[n-2][n-1] == grid[0][1]){
                    grid[n-2][n-1] ^= 1;
                    printf("%d %d\n", n - 1, n);
                }
                else{
                    grid[n-1][n-2] ^= 1;
                    printf("%d %d\n", n , n- 1);
                }
            }
        }
        else{
            if(grid[n-2][n-1] == grid[n-1][n-2] && grid[1][0] != grid[n-1][n-2]){
                printf("1\n");
                grid[0][1] ^= 1;
                printf("1 2\n");
            }
            else if(grid[n-2][n-1] == grid[n-1][n-2]){
                printf("1\n");
                grid[1][0] ^= 1;
                printf("2 1\n");
            }
            else{
                printf("2\n");
                if(grid[n-2][n-1] == grid[0][1]){
                    grid[n-2][n-1] ^= 1;
                    grid[1][0] ^= 1;
                    printf("%d %d\n", n-1, n);
                    printf("2 1\n");
                }
                else{
                    grid[n-2][n-1] ^= 1;
                    grid[0][1] ^= 1;
                    printf("%d %d\n", n-1, n);
                    printf("1 2\n");
                }
            }
        }
    }
}
