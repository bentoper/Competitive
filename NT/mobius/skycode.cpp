//http://poj.org/problem?id=3904
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

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
const int MAX_SIEVE = 10001;

vector<int> prim;

int mark[MAX_SIEVE], u[MAX_SIEVE];

ll freq[MAX_SIEVE];
	
void crivo(){
    u[1] = 1;
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), u[i] = -1;
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) {
                u[i*p] = 0;
                break;
            }
            u[i*p] = u[i]*u[p];
		}
	}
}

void update(int a){
    for(int i = 1; i*i <= a; i++){
        if(a%i == 0){
            freq[i]++;
            if(a/i != i) freq[a/i]++;
        }
    }
}

int main(){
    crivo();
    int n; 
    while(scanf("%d", &n) == 1){
        ms(freq, 0);
        fr(i, n){
            int a;
            scanf("%d", &a);
            update(a);    
        }
        ll ans = 0;
        frr(i, (int)1e4){
            if(!freq[i]) continue;
            ans += (ll)(u[i])*((freq[i]*(freq[i] - 1ll)*(freq[i]-2ll)*(freq[i]-3ll))/24ll);
        }
        printf("%lld\n", ans);
    }   
}
