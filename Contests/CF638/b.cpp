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

set<int> S;

int main(){
    rvr(t);
    while(t--){
        S.clear();
        int n, k; scanf("%d%d", &n, &k);
        vi arr;
        int sm = 0;
        fr(i, n){
            rvr(a);
            arr.pb(a);
            if(i < k) sm += a;
            S.insert(a);
        }
        if(k == n){
            printf("%d\n", n);
            vp(arr);
            continue;
        }
        if(S.size() > k){
            printf("-1\n");
            continue;
        }

        printf("%d\n", k*n);

        vi plc;
        for(auto p: S) plc.pb(p);
        while(plc.size() < k) plc.pb(*S.begin());
        fr(i, n){
            fr(j, k) printf("%d ", plc[j]);
        }
        printf("\n");
    }
}
