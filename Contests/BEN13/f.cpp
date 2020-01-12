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


int id[100100];
int sz[100100];
int find(int a){
    if(a == id[a]) return a;
    return id[a] = find(id[a]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    if(sz[a] > sz[b]) swap(a,b);
    id[a] = b;
    sz[b] += sz[a];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        int ans = 0;
        cin >> n >> m;
        frr(i,n){
            id[i] = i;
            sz[i] = 1;
        }
        fr(i,m){
            int a, b;
            cin >> a >> b;
            if(find(a) != find(b)){
                unite(a,b);
                ans++;
            }
        }
        cout << ans << endl;
    }

}
