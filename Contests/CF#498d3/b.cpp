#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], i==n-1);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 2123;


int n, k, a[N], b[N], f[N]; 

int main(){
    scanf("%d%d", &n, &k);
    fr(i, n){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a+n);
    for(int i = n-1, j = 0; i >= 0; j++, i--){
        if(j < k) f[a[i]]++;
    }
    int curr = 0;
    vi pos;
    pos.pb(0);
    fr(i, n){
        if(f[a[i]] && k){
            f[a[i]]--;
            k--;
            pos.pb(i);
        }
    }
    pos.pb(n);
    int aa = 0;
    fr(i, k - 1){
        int pp = pos[i+1] - pos[i];
        printf("%d ", pp);
        n -= pp;
    }
    printf("%d\n", n);
    
}