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

#define MAXN 	100100
#define LMAXN	18

vector<int> adj[MAXN];

int memo[MAXN][LMAXN + 1];
int hgt[MAXN];
int n;

int val[MAXN];
int freq[MAXN], what[MAXN];

vi qqq[MAXN], asopk[MAXN];

vi manc[MAXN], mver[MAXN];

void dfslca(int v){
	

	for(auto filho : adj[v]){
	
		if(hgt[filho] != -1) continue;
	
		memo[filho][0]=v;		
		hgt[filho]=hgt[v]+1;
		
		for(int i=1;i<LMAXN;i++){	
			if(memo[filho][i-1] != -1) memo[filho][i]=memo[memo[filho][i-1]][i-1];
            else break;
        }
        dfslca(filho);
	}
}

int vis[MAXN];

void dfs(int v){
	vis[v] = 1;
	freq[val[v]]++;
	for(auto i: manc[v]){
		qqq[i].pb(freq[what[i]]);
	}
	for(auto i: mver[v]){
		qqq[i].pb(freq[what[i]]);
	}
	for(auto u: adj[v]){
		if(vis[u]) continue;
		dfs(u);
	}
	freq[val[v]]--;
}

int lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);

	for(int i=LMAXN-1; i>=0; i-- ){
		if(memo[a][i] != -1 && hgt[ memo[a][i] ] >= hgt[b])	a=memo[a][i];
	}

	if(a==b)	return a;

	for(int i=LMAXN-1; i>=0; i--){
		if(memo[a][i] == -1 || memo[a][i] == memo[b][i]) continue;
		a=memo[a][i];
		b=memo[b][i];
	}

	return memo[b][0];
}

int main(){
    ms(memo, -1);
    ms(hgt, -1);
    int m;
    scanf("%d%d", &n, &m);
    frr(i, n) scanf("%d", &val[i]);
    fr(i, n-1){
        int x, y; scanf("%d%d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    hgt[1] = 0;
    dfslca(1);
	fr(i, m){
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		int ll = lca(a, b);
		manc[ll].pb(i);
		mver[a].pb(i);
		mver[b].pb(i);
		what[i] = c;
		asopk[i].pb(a);
		asopk[i].pb(b);
		asopk[i].pb(ll); 
	}
	dfs(1);
	fr(i, m){
		if(qqq[i][1] - qqq[i][0] > 0 || qqq[i][2] - qqq[i][0] > 0) printf("1");
		else if(val[asopk[i][0]] == what[i] || val[asopk[i][1]] == what[i] || val[asopk[i][2]] == what[i]) printf("1");
		else printf("0");
	}
	printf("\n");

}

