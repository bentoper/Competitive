//http://www.spoj.com/problems/GCDEX2/
//proof for summation can be found in: 
//https://mathproblems123.wordpress.com/2018/05/10/sum-of-the-euler-totient-function/
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
typedef uint64_t ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MAX_SIEVE = 10000002;


vector<ull> prim;

int mark[MAX_SIEVE], phi[MAX_SIEVE];

ull phipref[MAX_SIEVE], ans[MAX_SIEVE];

map<ull, ull> bigphi;

void crivo(){
    phi[1] = 1;
    phipref[1] = 1;
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i), phi[i] = i-1;
        phipref[i] = phipref[i-1] + (ull)phi[i];
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) {
                phi[i*p] = phi[i]*p;
                break;
            }
            phi[i*p] = phi[i]*(p-(ull)1);
		}
	}
}

ull longphi(ull x){
    if(x < MAX_SIEVE) return phipref[x];
    if(bigphi[x] != 0) {return bigphi[x];}
    ull sm;
    if(x%(ull)2 == 0){
        sm = x/(ull)2;
        sm *= (x+(ull)1);
    }
    else{
        sm = (x+(ull)1)/(ull)2;
        sm *= x;
    }
    ull plc = 0;
    for(ull i = 1; i*i <= x; i++){
        if(i > 1) plc += longphi(x/i);
        if(x/i != i) plc += longphi(i)*(x/i - x/(i+1));
    }
    return (bigphi[x] = sm - plc);
}

int main(){
    crivo();
    int T; scanf("%d", &T);
    while(T--){
        ull n; scanf("%lu", &n);
        ull G = 0;
        for(ull i = 1; i*i <= n; i++){
            G += i*(longphi(n/i) - (ull)1);
            if(n/i != i) G += (longphi(i) - (ull)1)*(((n/i + (n/(i+(ull)1) + (ull)1))*(n/i - n/(i+(ull)1)))/(ull)2); 
        }
        printf("%lu\n", G);
    }
}
