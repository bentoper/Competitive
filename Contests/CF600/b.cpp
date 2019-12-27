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
const int N = 1e6 + 1;

int op[N], n, a[N];


int main(){
    scanf("%d", &n);
    fr(i, n){
        scanf("%d", &a[i]);
    }

    vi ans;
    int i = 0, curr = 0, d = 1, qnt = 0;
    bool cagou = false;
    while(i < n){
        if(a[i] < 0 && op[-a[i]] <= 0){
            cagou = true;
            break;
        }
        else if(a[i] < 0){
            op[-a[i]] = -d;
            curr--;
            qnt++;
        }
        if(a[i] > 0 && op[a[i]] > 0 || a[i] > 0 && -op[a[i]] == d){
            cagou = true;
            break;
        }
        else if(a[i] > 0){
            op[a[i]] = d;
            curr++;
            qnt++;
        }
        if(curr == 0){
            d++;
            ans.pb(qnt);
            qnt = 0;
        }
        i++;
    }
    if(!cagou && curr == 0){
        printf("%d\n", (int)ans.size());
        pv(ans, ans.size());
    }
    else printf("-1\n");

}
