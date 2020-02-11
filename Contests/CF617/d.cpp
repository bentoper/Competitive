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
const int N = 2e5 + 1;

int h[N];


int main(){
    int n, a, b, k; scanf("%d%d%d%d", &n, &a, &b, &k);
    int p = 0, plc = a + b;
    vi nd;
    fr(i, n){
        scanf("%d", &h[i]);
        int vaca = h[i]%plc;
        if(vaca <= a && vaca != 0) p++;
        else{
            if(vaca == 0) vaca = a + b;
            nd.pb((vaca - 1)/a);
        }
    }
    sort(all(nd));
    int i = 0, sz = nd.size();
    while(k > 0 && i < sz){
        if(k < nd[i]) break;
        k -= nd[i];
        p++;
        i++;
    }
    printf("%d\n", p);
}
