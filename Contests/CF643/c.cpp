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
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans = 0;
    for(int i = a; i <= b; i++){
        if(i + b > d){
            ans += (ll)(d - c + 1)*(ll)(c - b + 1);     
        }
        else if(i + b <= c){
            if(i + c > d){
                ans += (ll)(d - c + 1)*(ll)(i + c - d);
                ans += ((ll)(1 + d - c)*(ll)(d - c))/2ll;
            }
            else{
                ans += ((ll)(1 + i)*(ll)(i))/2ll;
            }
        }
        else{
            if(i + c > d){
                ans += (ll)(d - c + 1)*(ll)(i + c - d);
                ans += ((ll)(i + b - c + d - c)*(ll)(d - (i + b) + 1))/2ll;
            }
            else{
                ans += ((ll)(2*i + b - c)*(ll)(c - b + 1))/2ll;
            }
        }
    }
    printf("%lld\n", ans);

}
