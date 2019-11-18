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
const int N = 1111;

int n, m, d, c[N], pos[N];
int ans[N];

bool solve(){
    ans[0] = 0;
    int j = 0;
    pos[0] = 0;
    frr(i, m){
        fr(k, c[i]) ans[++j] = i;
        pos[i] = j;
    }
    int r = n+1;
    for(int i = m; i >= 0; i--){
        j = pos[i];
        if(j + d >= r) return true;
        else if(i == 0) return false;
        int jj = j;
        while(jj + d < r) {
            ans[jj + 1] = i;
            ans[jj - c[i] + 1] = 0;
            jj++;
        }
        jj--;
        r = jj - c[i] + 2;
    }
    return true;
}

int main(){
    scanf("%d%d%d", &n, &m, &d);
    frr(i, m) scanf("%d", &c[i]);
    if(!solve()){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        frr(i, n){
            if(i > 1) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
