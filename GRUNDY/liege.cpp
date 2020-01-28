//https://codeforces.com/problemset/problem/603/C
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
const int N = 1e6 + 2;

int g[N], k;

int dp(int n){
    if(n < N && g[n] != -1) return g[n];
    else{
        if(n%2==0 && k%2==0) return 1;
        else if(n%2 == 0) return (dp(n/2)==1)?2:1;
        else return 0;
    } 
}

int main(){
    int n; scanf("%d%d", &n, &k);
    ms(g, -1);
    ll xr = 0;
    g[1] = 1;
    if(k%2){
        g[2] = 0;
        g[3] = 1;
        g[4] = 2;
        g[5] = 0;
        g[6] = 2;
        g[7] = 0;
        g[8] = 1;
    }
    else{
        g[2] = 2;
        g[3] = 0;
        g[4] = 1;
        g[5] = 0;
        g[6] = 1;
        g[7] = 0;
        g[8] = 1;
    }
    fr(i, n){
        int a; scanf("%d", &a);
        xr ^= dp(a);
    }
    if(xr == 0){
        printf("Nicky\n");
    } 
    else printf("Kevin\n");
}
