#include <bits/stdc++.h>
using namespace std;

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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int a[1001];

bool deu(int a){
    int l = 1, r = a/2 + 1;
    while(l <= r){
        int mid = (l+r)>>1;
        ll plc = (ll)mid*(ll)mid;
        if(plc == a) return true;
        if(plc > a) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

int main(){
    int n; scanf("%d", &n);
    fr(i, n) scanf("%d", &a[i]);
    sort(a, a+n);
    for(int i = n-1; i >= 0; i--){
        if(a[i] < 0){
            printf("%d\n", a[i]);
            return 0;
        }
        else if(a[i] > 0){
            if(!deu(a[i])){
                printf("%d\n", a[i]);
                return 0;
            }
        }
    }
}
