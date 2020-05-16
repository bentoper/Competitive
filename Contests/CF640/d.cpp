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
    rvr(t);
    while(t--){
        rvr(n);
        vi v;
        fr(i, n){
            rvr(a);
            v.pb(a);
        }
        int la = 0, lb = 0, mv = 0, i = 0, j = n-1, cur = 0;
        int ra = 0, rb = 0;
        while(1){
            if(cur == 0){
                mv++;
                la = 0;
                do{
                    la += v[i++];
                }while(la <= lb && i <= j);
                ra += la;
                if(i > j) break;
                cur = 1;
            }
            else{
                mv++;
                lb = 0;
                do{
                    lb += v[j--];
                }while(lb <= la && i <= j);
                rb += lb;
                if(i > j) break;
                cur = 0;
            }
        }
        printf("%d %d %d\n", mv, ra, rb);
    }
}
