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

int main(){
    int plc = 1e9;
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int ncp = n;
        int i = 0;
        int ops;
        while(ncp > 0){
            if(ncp < 10) ops = ncp;
            i++;
            ncp /= 10;
        }
        i--;
        int ans = 9*i;
        int vaca = 10;
        fr(j, i){
            vaca *= 10;
        }
        int fcp = ops;
        fr(j, i){
            fcp *= 10;
            fcp += ops;
        }
        if(n >= fcp){
            ans += ops;
        }
        else ans += ops-1;
        printf("%d\n", ans);    
    }
}
