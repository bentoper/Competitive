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
const int N = 1e5 + 1;

int a[N], b[N];

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        fr(i, n) cin >> a[i];
        fr(i, n){
            cin >> b[i];
            b[i] -= a[i];
        }
        bool z = true, deu = true, cagou = false;
        fr(i, n){
            if(b[i] < 0){
                cagou = true;
                break;
            }
            if(b[i] != 0 && z){
                z = false;
                i++;
                while(i < n && b[i] != 0){
                    if(b[i] != b[i-1]) {cagou = true; break;}
                    i++;
                }
            }
            else if(b[i] != 0) cagou = true;
            if(cagou) break;
        }
        if(!cagou) cout << "YES\n";
        else cout << "NO\n";
    }
}
