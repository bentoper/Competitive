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
const int mod = 1e9 + 7;
const int MAX = 1e5 + 1;
string s;
vi qnt;
int sz;

map<pii, ll> fac;

ll memo[MAX];

ll dp(int i){
    if(i == 0) return 1;
    if(i == 1) return 1;
    if(memo[i] != -1) return memo[i];
    return memo[i] = (dp(i-1) + dp(i-2))%mod;
}

int main(){
    ms(memo, -1);
    string s; cin >> s;
    int n = s.size(), sz = n;
    fr(i, n){
        if(s[i] == 'w' || s[i] == 'm'){
            cout << "0\n";
            return 0;
        }
        if(s[i] == 'u' || s[i] == 'n'){
            char curr = s[i];
            int cnt = 0;
            do{
                i++;
                cnt++;
            }while(i < n && s[i] == curr);
            i--;
            qnt.pb(cnt);
        }
    }
    ll ans = 1;
    for(auto f: qnt){
        if(f == 1) continue;
        ll plc = dp(f);
        ans *= plc;
        ans %= mod;   
    }
    cout << ans << endl;
}
