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
        int n; scanf("%d", &n);
        if(n < 3 || n == 4){
            printf("-1\n");
            continue;
        }
        if(n == 7){
            printf("0 0 1\n");
            continue;
        }
        int t = 0, f = 0, s = 0;
        if(n%10 == 3 || n%10 == 8){
            t++;
            n -= 3;
        }
        else if(n%10 == 6 || n%10 == 1){
            t+=2;
            n -= 6;
        }
        else if(n%10 == 7){
            s++;
            n -=7;
        }
        else if(n%10 == 9){
            t += 3;
            n -= 9;
        }
        else if(n%10 == 2){
            t += 4;
            n -= 12;
        }
        else if(n%10 == 4){
            s += 2;
            n -= 14;
        }
        f += n/5;

        printf("%d %d %d\n", t, f, s);
    }
}
