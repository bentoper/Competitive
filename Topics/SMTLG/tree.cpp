//https://www.e-olymp.com/en/problems/2923
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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
const int MAXN = 1e6 + 10;

vi adj[MAXN];
int ans[MAXN], cor[MAXN], sz[MAXN];

void dfs(int r, unordered_map<int, int> &m){
    for(int v: adj[r]){
        unordered_map<int, int> plc;
        dfs(v, plc);
        if(plc.size() > m.size()){
            swap(plc, m);
        }
        for(pii p: plc){
            m[p.first]++;
        }
    }
    m[cor[r]]++;
    ans[r] = m.size();
}


int main(){
    int n; scanf("%d", &n);
    int r;
    frr(i, n){
        int p, c;
        scanf("%d%d", &p, &c);
        if(p == 0) r = i;
        else adj[p].pb(i);
        cor[i] = c;
    }
    unordered_map<int, int> m;
    dfs(r, m);
    frr(i, n){
        printf("%d%c", ans[i], " \n"[i==n]);
    }
}