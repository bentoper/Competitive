#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

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
const int N = 212345;


int n;

ll dp[N];
int par[N];
pii a[N];
int id[N];

int main(){
    scanf("%d", &n);
    fr(i, n) {
        dp[i+1] = llINF;
        int c; scanf("%d", &c);
        a[i] = mp(c, i);
        par[i] = -1;
    }
    par[n] = -1;
    sort(a, a + n);
    for(int i = 0; i <= n - 3; i++){
        if(dp[i] == llINF) continue;
        fr(j, 3){
            int val = i + 3 + j;
            if(val > n) continue;
            int plc = dp[val]; 
            dp[val] = min(dp[val], dp[i] + (ll)(a[val - 1].first) - (ll)(a[i].first));
            if(dp[val] < plc){
                par[val] = i;
            }
        }
    }
    printf("%lld ", dp[n]);
    stack<int> s;
    int x = n;
    s.push(n);
    while(x != -1){
        s.push(x);
        x = par[x];
    }
    int vaca = s.size() - 2;
    printf("%d\n", vaca);
    int l = s.top(), r;
    s.pop();
    r = s.top();
    frr(i, vaca){
        for(int k = l; k < r; k++){
            id[a[k].second] = i;
        }
        l = r;
        if(!s.empty()){
            s.pop();
            r = s.top();
        }

    }
    fr(i, n){
        if(i > 0) printf(" ");
        printf("%d", id[i]);
    }
    printf("\n");
}