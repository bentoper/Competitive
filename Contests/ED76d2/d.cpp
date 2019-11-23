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
#define rvr(x) int x; scanf("%d", &x);
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

int s[N], a[N], n, m;


int solve(int l){
    if(l == n + 1) return 0;
    int i = 0;
    int plc = a[l+i];
    while(l + i <= n && s[i + 1] >= (plc = max(plc, a[l + i]))) i++;
    return 1 + solve(l + i);
    
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int mmax = 0;
        scanf("%d", &n);
        frr(i, n){
            s[i] = 0;
            scanf("%d", &a[i]);
            mmax = max(a[i], mmax);
        }
        scanf("%d", &m);
        frr(i, m){
            int p, e;
            scanf("%d%d", &p, &e);
            s[e] = max(s[e], p);
        }
        int mx = 0;
        for(int e = n; e > 0; e--){
            s[e] = max(mx, s[e]);
            mx = s[e];
        }
        if(mx < mmax){
            printf("-1\n");
            continue;
        }
        printf("%d\n", solve(1));
    }
}