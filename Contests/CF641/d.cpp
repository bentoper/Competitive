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
        int n, k; scanf("%d%d", &n, &k);
        int last[2] = {-1, -1};
        bool deu = false, achou = false;
        fr(i, n){
            rvr(a);
            if(n == 1){
                if(a == k) printf("yes\n");
                else printf("no\n");
                goto END;
            }
            if(a == k) achou = true;
            if(last[0] != -1){
                if(last[1] != -1 && last[1] >= k && a >= k) deu = true;
                if(a >= k && last[0] >= k) deu = true;
            }
            swap(last[0], last[1]);
            last[0] = a;
        }
        if(deu && achou) printf("yes\n");
        else printf("no\n");
        END:;
    }
}
