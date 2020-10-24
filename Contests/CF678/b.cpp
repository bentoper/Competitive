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

int main(){
    tsts(t){
        rvr(n);
        if(n == 2){
            printf("1 1\n1 1\n");
        }
        else if(n == 3){
            printf("1 1 1\n1 1 1\n1 1 1\n");
        }
        else if(n == 4){
            printf("4 6 8 1\n4 9 9 9\n4 10 10 65\n1 4 4 4\n");
        }
        else if(n >= 5){
            vector<vi> grid(n, vi(n, 1));
            int cur = 0, diff  = n - 5;
            fr(i, n){
                fr(j, diff){
                    grid[i][(cur + j)%n] = 0;
                }
                fr(j, n){
                    printf("%d ", grid[i][j]);
                }
                cur++;
                printf("\n");
            }
        }
    }
}
