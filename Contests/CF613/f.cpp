#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(csi, n) printf("%d%c", x[csi], " \n"[csi==n-1])
#define pvv(x, n)    frr(csi, n) printf("%d%c", x[csi], " \n"[csi==n])

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
const int MAX_SIEVE = 1e5 + 2;
const int N = MAX_SIEVE;

vector<int> prim;
int mark[MAX_SIEVE], u[N], a[N], freq[N], mul[N];

vi f[N];
	
void crivo(){
    u[1] = 1;
	for(int i = 2; i < MAX_SIEVE; i++){
        if(!mark[i]){
            prim.pb(i);
            u[i] = -1;
        }
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0){
                u[i*p] = 0;
                break;
            }
            else u[i*p] = u[i]*u[p];
		}
	}
}

bool coprime(int x){
    int sm = 0;
    for(auto d: f[x]){
        sm += u[d]*mul[d];
    }
    return (sm > 0);
}

void tk(int x){
    for(auto d: f[x]) mul[d]--;
}

void pt(int x){
    for(auto d: f[x]) mul[d]++;
}

int main(){
    int n; scanf("%d", &n);
    crivo();
    int mx = -1;
    fr(i, n) scanf("%d", &a[i]), mx = max(a[i], mx), freq[a[i]]=1;
    frr(i, mx){
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){
                if(i/j==j) f[i].pb(j);
                else f[i].pb(i/j), f[i].pb(j);
            }
        }
    }
    ll ans = mx;
    for(int i = mx; i > 0; i--){
        stack<int> stk;
        for(int j = mx/i; j > 0; j--){
            if(freq[i*j] == 0) continue;
            while(coprime(j)){
                ans = max(ans, ((ll)stk.top()*(ll)j*(ll)i));
                tk(stk.top());
                stk.pop();
            }
            pt(j);
            stk.push(j);
        }
        while(!stk.empty()){
            tk(stk.top());
            stk.pop();
        }
    }
    printf("%lld\n", ans);
}
