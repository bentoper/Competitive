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
    int t; cin >> t;
    while(t--){
        int c[3];
        cin >> c[0] >> c[1] >> c[2];
        sort(c, c+3);
        int ans = 0;
        if(1){
            if(c[0] >= c[2] - c[1]){
                ans += c[2] - c[1];
                c[2] = c[1];
                c[0] -= ans;
            }
            else{
                c[2] -= c[0];
                ans += c[0];
                c[0] = 0; 
            }
            if(c[0]%2 == 0){
                ans += c[0];
                ans += min(c[1] - c[0]/2, c[2] - c[0]/2);
            }
            else{
                ans += c[0] - 1;
                ans += min(c[1] - c[0]/2, c[2] - c[0]/2);
            }
        }
        printf("%d\n", ans);
    }
}
