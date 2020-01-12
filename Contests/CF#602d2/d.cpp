#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
        tree_order_statistics_node_update> ordered_set;


const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 3e5;

int n, a[N], m, ans[N];

pii ord[N];

pair<pii, int> q[N];

int main(){
    scanf("%d", &n);
    fr(i, n){
        scanf("%d", &a[i]);
        ord[i] = mp(-a[i], i);
    }
    sort(ord, ord+n);
    scanf("%d", &m);
    fr(i, m){
        rvr(a); rvr(b);
        q[i] = mp(mp(a, b), i);
    }
    sort(q, q+m);
    ordered_set s;
    int j = 0;
    fr(i, m){
        while(j < q[i].first.first){
            s.insert(ord[j++].second);
        }
        ans[q[i].second] = a[*s.find_by_order(q[i].first.second - 1)];
    }
    pv(ans, m);
}
