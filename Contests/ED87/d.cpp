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
const int N = 1e6 + 1;

int a[N], k[N], n, q, pref[N];

bool solve(int val){
    int base = pref[val];
    fr(i, q){
        if(k[i] < 0 && -k[i] <= base){
            base--;
        }
        else if(k[i] > 0 && k[i] <= val) base++;
    }

    return base > 0;
}

int main(){
    scanf("%d%d", &n, &q);
    int cnt = 0;
    fr(i, n){
        scanf("%d", &a[i]);
        pref[a[i]]++;
    }
    frr(i, n) pref[i] += pref[i-1];
    fr(i, q){
        scanf("%d", &k[i]);
        if(k[i] < 0) cnt++;
    }
    if(n + q - cnt == cnt){
        printf("0\n");
        return 0;
    }
    int r = n, l = 1, ans = INF;
    while(l <= r){
        int mid = (l + r)/2;
        if(solve(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1; 
    }
    printf("%d\n", ans);
}
