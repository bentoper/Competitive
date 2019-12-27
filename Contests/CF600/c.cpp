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
const int N = 2e6 + 1;


int n, m, a[N];

vector<vll> sm;

int main(){
    scanf("%d%d", &n, &m);
    fr(i, n){
        scanf("%d", &a[i]);
    }
    sm.resize(m);
    sort(a, a+n);
    int i = 0;
    while(i < n){
        if(sm[i%m].empty()){
            sm[i%m].pb(a[i]);
        }
        else sm[i%m].pb(sm[i%m][sm[i%m].size() - 1] + (ll)a[i]);
        i++;
    }
    i = 0;
    ll S = 0;
    while(i < n){
        if(i < m){
            S += (ll)a[i];
        }
        else{
            S += sm[i%m][i/m - 1];
            S += a[i];
        }
        printf("%lld%c", S, " \n"[i == n-1]);
        i++;
    }

}
