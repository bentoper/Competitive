//https://codeforces.com/problemset/problem/471/D
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

vector<int> z_function(vll s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    rvr(n); rvr(w);
    vll bear;
    int last;
    int ans = 0;
    fr(i, n){
        rvr(a);
        if(i != 0) bear.pb(a - last);
        last = a; 
    }
    vll ele;
    fr(i, w){
        rvr(a);
        if(i != 0) ele.pb(a - last);
        last = a;
    }
    ele.pb((ll)1e10);
    if(w == 1){
        cout << n << endl;
    }
    if(w > n){
        cout << 0 << endl;
    }
    if(w == 1 || w > n) return 0;
    fr(i, n-1) ele.pb(bear[i]);
    vi z = z_function(ele);
    for(int i = w; i < w - 1 + n; i++){
        if(z[i] == w-1) ans++;
    }
    cout << ans << endl;
}