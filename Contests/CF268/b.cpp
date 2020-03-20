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
const int MAXN = 4e5 + 1;

ll clk = 0, qnt = 0;

int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

bool eval[MAXN];

vector<int> adj[MAXN];

stack<int> nodes;

void dfs(int v){

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];

	for(auto x: adj[v]){
		if(pre[x] == -1){
			dfs(x);
		}
		low[v] = min(low[v], low[x]);
	}

	if(low[v] == pre[v]){
		while(true){
			int j = nodes.top();
			nodes.pop();
			id[j] = numSCC;
			low[j] = MAXN;
			if(j == v) break;
		}
		numSCC++;
	}

}

int neg(int i){
	if(i <= qnt/2) return i + qnt/2;
	return i - qnt/2; 
}


void add_imp(int i, int j){
	adj[i].pb(j);
}

void add_or(int i, int j){
	add_imp(neg(i), j);
	add_imp(neg(j), i);
}

void add_xor(int i, int j){
	add_or(i, j);
	add_or(neg(i), neg(j));
}

void force_var(int i){
	add_imp(neg(i), i);
}

bool sat(){
	for(int i = 1; i <= qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 1; i <= qnt/2; i++){
		if(id[i] == id[neg(i)]) return false;
		eval[i] = id[i] < id[neg(i)];
		eval[neg(i)] = !eval[i];
	}

	return true;
}

int a[MAXN];

map<int, int> idd;

int main(){
    ms(pre, -1);
    rvr(n); rvr(x); rvr(y);
    frr(i, n) scanf("%d", &a[i]), idd[a[i]] = i;
    qnt = 4*n;
    frr(i, n){
        int A = idd[x-a[i]], B = idd[y-a[i]];
        if(A == 0 && B == 0){
            printf("NO\n");
            return 0;
        }
        add_xor(2*i - 1, 2*i);
        if(A) add_imp(2*i - 1, 2*A - 1), add_imp(2*A - 1, 2*i - 1), add_imp(neg(2*A - 1), neg(2*i - 1)), add_imp(neg(2*i - 1), neg(2*A - 1)); 
        if(B) add_imp(2*i, 2*B), add_imp(2*B, 2*i), add_imp(neg(2*B), neg(2*i)), add_imp(neg(2*i), neg(2*B)); 
        if(!B) force_var(2*i - 1);
        else if(!A) force_var(2*i);
    }
    if(sat()){
        printf("YES\n");
        frr(i, n){
            printf("%d%c", eval[2*i-1]?0:1, " \n"[i==n]);
        }
    }
    else printf("NO\n");
}
