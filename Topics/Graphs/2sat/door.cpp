//https://codeforces.com/contest/776/problem/D
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

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

#define MAXN 812345 //twice amount of stuff

ll clk = 0, qnt = 0;

int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

int r[MAXN];

vector<int> adj[MAXN], rms[MAXN];

stack<int> nodes;

void dfs(int v){

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];

	for(auto x: adj[v]){
		if(pre[x] == -1){
			dfs(x);
		    low[v] = min(low[v], low[x]);
		}
        else low[v] = min(low[v], low[x]);
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

void  add_iff(int i, int j){
	add_imp(i, j);
	add_imp(neg(i), neg(j));
	add_imp(j, i);
	add_imp(neg(j), neg(i));
}

bool sat(){
	for(int i = 1; i <= qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 1; i <= qnt/2; i++){
		if(id[i] == id[neg(i)]) return false;
	}

	return true;

}

int main(){
    int n, m;
    ms(pre, -1);
    scanf("%d%d", &n, &m);
    frr(i, n){
        scanf("%d", &r[i]);
    }
    frr(i, m){
        int q; scanf("%d", &q);
        fr(j, q){
            int a; scanf("%d", &a);
            rms[a].pb(i);
        }
    }
    qnt = 2*m;
    frr(a, n){
        if(r[a] == 0){
            add_xor(rms[a][0], rms[a][1]);
        }
        else add_iff(rms[a][0], rms[a][1]);
    }
    if(sat()) printf("YES\n");
    else printf("NO\n");
}