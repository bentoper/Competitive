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

vll av;

int main(){
    int T; cin >> T;
    while(T--){
        ll n, x; cin >> n >> x;
        string s; cin >> s;
        ll qnt = 0;
        ll ans = 0;
        fr(i, n){
            qnt += (s[i] == '1'?-1:1);
            av.pb(qnt);
        }
        bool deu = true;
        fr(i, n){
            ll plc = x - av[i];
            if(plc == 0 && qnt == 0){
                deu = false;
                break;
            }
            if(plc < 0 && qnt > 0 || qnt < 0 && plc > 0) continue;
            if(qnt != 0 && abs(plc)%abs(qnt) == 0) ans++;
        }
        if(!deu){
            printf("-1\n");
            continue;
        }
        if(x == 0) ans++;
        printf("%d\n", ans);
    }
}
