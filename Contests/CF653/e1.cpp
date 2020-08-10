#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


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

struct blob{
    int t, a, b;
};


blob arr[N];

bool comp(const blob a, const blob b){
    if(a.t < b.t) return 1;
    if(a.t == b.t && a.a + a.b > b.b + b.a) return 1;
    return 0;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    fr(i, n){
        scanf("%d%d%d", &arr[i].t, &arr[i].a, &arr[i].b);
    }
    sort(arr, arr+n, comp);
    stack<int> A, B, C;
    fr(i, n){
        if(arr[i].a == 1 && arr[i].b == 0 && A.size() < k) A.push(i);
        if(arr[i].b == 1 && arr[i].a == 0 && B.size() < k) B.push(i);
    }
    fr(i, n){
        if(!(arr[i].b && arr[i].a)) continue;
        if(A.size() + C.size() < k || B.size() + C.size() < k){
            C.push(i);
            if(B.size() + C.size() > k) B.pop();
            if(A.size() + C.size() > k) A.pop();
            continue;
        }
        if(A.empty() || B.empty()) break;
        if(arr[i].t < arr[B.top()].t + arr[A.top()].t){
            A.pop();
            B.pop();
            C.push(i);
        }        
    }
    if(A.size() + C.size() < k || B.size() + C.size() < k){
        printf("-1\n");
        return 0;
    }
    ll ans = 0;
    while(!A.empty()) {ans += (ll) arr[A.top()].t, A.pop();}
    while(!B.empty()) {ans += (ll) arr[B.top()].t, B.pop();}
    while(!C.empty()) {ans += (ll) arr[C.top()].t, C.pop();}
    printf("%lld\n", ans);

}
