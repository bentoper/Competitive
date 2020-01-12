#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug printf

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

int dist[1111];
ll comb[1111][1111];


int dp(int i, int j){
    if(i == j) return(comb[i][j] = 1);
    if(j == 0) return(comb[i][j] = 1);
    if(comb[i][j] != 0) return comb[i][j];
    return(comb[i][j] = (dp(i - 1, j) + dp(i - 1, j - 1))%mod);
}

void build(){
    frr(i, 1000){
        int copy = i;
        while(copy != 1){
            dist[i]++;
            copy = __builtin_popcount(copy);
        }
    }
}

int main(){
    fastio;
    build();
    frr(i, 1000){
        for(int j = i; j <= 1000; j++) dp(j, i);
    }
    string s; cin >> s;
    int k; cin >> k;
    k--;
    int m = s.size();
    if(k == -1){
        printf("1\n");
        return 0;
    }
    if(m == 1){
        printf("0\n");
        return 0;
    }
    ll ans = 0;
    int cnt = 0;
    fr(i, m){
        if(s[i] == '1'){
            int sz = m - i - 1;
            frr(j, sz){
                if(dist[j+cnt] == k) ans += comb[sz][j];
                ans %= mod;
            }
            cnt++;
            if(dist[cnt] == k) ans++, ans %= mod;
        }
    }
    if(k == 0) ans--;
    cout << ans << endl;
}
