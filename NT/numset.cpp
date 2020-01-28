//https://open.kattis.com/problems/numbersetshard
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
const int MAX_SIEVE = 1e6 + 2;

// par inicializa com p[i] = i e peso = 0, qnt = 1;
int par[N], depth[N], sz[N];

vector<int> prim;
int mark[MAX_SIEVE];
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i);
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}


int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;

}

int main(){
    crivo();
    int T; scanf("%d", &T);
    frr(clk, T){
        ll a, b, P; scanf("%lld%lld%lld", &a, &b, &P);
        frr(i, b-a + 1){
            par[i] = i;
            sz[i] = 0;
        }
        ll cnt = b-a + 1ll;
        for(ll p: prim){
            if(p < P) continue;
            for(ll j = (a - 1ll)/p + 1ll, frst = j*p - a + 1ll; j*p <= b; j++){
                if(find(j*p - a + 1ll) != find(frst)){
                    cnt--;
                    join(j*p - a + 1ll, frst);
                }
            }
        }
        printf("Case #%d: %lld\n", clk, cnt);
    }    
}
