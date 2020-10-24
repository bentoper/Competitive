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
#define tsts(t) rvr(t); while(t--)


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

int x[] = {1, -1, 0, 0}, y[] = {0, 0, -1, 1};

int main(){
    int n, m; scanf("%d%d", &n, &m);
    vector<vi> grid(n, vector<int>(3, 0));
    fr(i, n){
        int p;
        char c;
        cin >> p >> c;
        p--;
        int val = 2;
        if(c == 'H'){
            val = 0;
        }
        else if(c == 'M'){
            val = 1;
        }
        grid[p][val] = 1;
        fr(k, 4){
            if(p + x[k] < n && p + x[k] > 0 && val + y[k] > 0 && val + y[k] < 3) grid[p+x[k]][val+y[k]] = 1;
        }
    }
}
