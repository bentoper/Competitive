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


int n, k;
int id[600];
int main(){
    scanf("%d%d", &n, &k); 
    int i = 1;
    int cnta = 0, cntb = 0, a = -1, b = -1;
    while(i <= k+1){
        printf("? ");
        int cnt = 0;
        frr(j, k+1){
            if(j!=i){
                cnt++; 
                printf("%d%c", j, " \n"[cnt==k]);
            }
        } 
        fflush(stdout);
        int pos, val; scanf("%d%d", &pos, &val);
        if(a == -1){
            a = val;
            cnta++;
        }
        else if(a == val){
            cnta++;
        }
        else if(b == -1){
            b = val;
            cntb++;
        }
        else cntb++;
        i++;
    }
    printf("! %d\n", a>b?cnta:cntb);
    fflush(stdout);
}
