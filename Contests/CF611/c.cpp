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
const int N = 2e5 + 10;

int f[N], used[N];
vi give, receive;

int main(){
    int n; cin >> n;
    frr(i, n)  {cin >> f[i]; used[f[i]] = 1; if(f[i] == 0) give.pb(i);}
    frr(i, n){
        if(!used[i]) receive.pb(i);
    }
    fr(i, give.size()){
        if(give[i] == receive[i]){
            if(i == 0) swap(give[i], give[i+1]);
            else swap(give[i], give[i-1]);
        }
    }
    fr(i, give.size()){
        f[give[i]] = receive[i];
    }
    frr(i, n){
        cout << f[i] << " \n"[i==n];
    }
}
