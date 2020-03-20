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

int main(){
    rvr(n);
    if(n <= 3){
        printf("NO\n");
        return 0;
    }
    else if(n==5){
        printf("YES\n");
        printf("5 * 4 = 20\n3 - 1 = 2\n2 * 2 = 4\n4 + 20 = 24\n");
            
    } 
    else if(n == 4){
        printf("YES\n");
        printf("2 * 3 = 6\n");
        printf("4 * 6 = 24\n24 * 1 = 24\n");
    }
    if(n <= 5) return 0;
    printf("YES\n");
    printf("6 * 4 = 24\n2 + 3 = 5\n5 - 5 = 0\n");
    for(int i = 7; i <= n; i++) printf("%d * 0 = 0\n", i);
    printf("24 + 0 = 24\n24 * 1 = 24\n");
}
