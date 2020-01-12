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
const int N = 2e5 + 1;

int a[N], n, l[N], r[N];

int main(){
    scanf("%d", &n);
    fr(i, n) {scanf("%d", &a[i]), l[i] = 1, r[i] = 1;}
    int ans = -1; 
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1]) l[i] = l[i-1] + 1;
        if(a[n - i - 1] < a[n - i]) r[n - i - 1] = r[n - i] + 1; 
        ans = max(ans, l[i]);
    }
    for(int i = 1; i < n - 1; i++){
        if(a[i-1] < a[i+1]) ans = max(ans, l[i-1] + r[i+1]);
    }
    printf("%d\n", ans);
}
