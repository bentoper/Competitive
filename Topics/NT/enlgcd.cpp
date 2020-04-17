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
const int MAX_SIEVE = 15000001;
const int N = 3e5 + 1;

vector<int> prim, qnt;
int mark[MAX_SIEVE], lp[MAX_SIEVE], sp[MAX_SIEVE];
int arr[N];

void crivo(){
    lp[1] = 1, sp[1] = 1;
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), lp[i] = i, sp[i] = i;
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0){
                lp[i*p] = lp[i]*p;
                sp[i*p] = p;
                break;
            }
            sp[i*p] = min(sp[i], p);
            if(sp[i*p] == p) lp[i*p] = p;
            else lp[i*p] = lp[i];
		}
	}
}

int main(){
    crivo();
    int seqgcd = 0;
    int n; scanf("%d", &n);
    fr(i, n) scanf("%d", &arr[i]), seqgcd = __gcd(arr[i], seqgcd);
    fr(i, n){
        arr[i] /= seqgcd;
        while(arr[i] != 1){
            mark[sp[arr[i]]]++;
            arr[i] /= lp[arr[i]];
        }
    }
    int ans = -1;
    for(auto p: prim){
        ans = max(mark[p], ans);        
    }
    if(ans == 0) ans = -1;
    else ans = n - ans;
    printf("%d\n", ans);
}
