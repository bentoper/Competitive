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


int a[(int)2e5+1];

int main(){
    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        ll sm = 0; 
        int mx = -1, qnt = 0;
        bool tirei = false;
        fr(i, n){
            cin >> a[i];
        }
        int i = 0;
        int ans = 0;
        while(sm <= s && i < n){
            sm += a[i];
            if(mx < a[i] && !tirei){
                ans = i;
                mx = a[i];
            }
            if(sm > s && !tirei){
                sm -= mx;
                tirei = true;
            }
            else if(sm > s){
                break;
            }
            else qnt++;
            i++;
        }
        if(tirei) cout << ans + 1 << endl;
        else cout << 0 << endl;
    }
}
