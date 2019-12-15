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


int n, k, a[N], b[N], freq[N]; 

int main(){
    scanf("%d%d", &n, &k);
    fr(i, n){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    int ans = 0;
    sort(b, b+n);
    for(int i = n - 1, kk = 0; kk < k; kk++, i--) {ans += b[i]; freq[b[i]]++;}
    int cnt = 0, i = 0, kk = 0, lst = 0;
    printf("%d\n", ans);
    while(i < n){
        cnt++;
        if(freq[a[i]]){
            kk++;
            if(k == kk){
                printf("%d\n", n - lst);
                return 0;
            }
            else{
                printf("%d ", cnt);
                cnt = 0;
                lst = i + 1;
            }
            freq[a[i]]--;
        }
        i++;
    }

}