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
const int MAX = 2e5 + 1;

vii edges;
int pai[MAX], qnt[MAX];
set<int> comp;

bool mycomp(pii a, pii b){
    if(a.second < b.second) return 1;
    if(a.second == b.second && a.first < b.first) return 1;
    return 0;
}

int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

int join(int x, int y){
	if((x = find(x)) == (y = find(y))) return -1;

	if(qnt[x] > qnt[y]) swap(x, y);

	pai[x] = y;
	qnt[y] += qnt[x];
    
    return x;
}

int main(){
    int n, m; scanf("%d%d", &n, &m);
    fr(i, m){
        rvr(a); rvr(b);
        if(b > a) swap(a, b);
        edges.pb(mp(b, a));
    }
    frr(i, n){
        pai[i] = i;
        qnt[i] = 1;
    }
    sort(all(edges), mycomp);
    int pos = 0;
    frr(i, n){
        comp.insert(i);
        map<int, int> ed;
        while(pos < m && edges[pos].second == i){
            ed[find(edges[pos].first)]++;
            pos++;
        }
        vi rm;
        for(int u: comp){
            if(find(u) != find(i) && ed[find(u)] < qnt[find(u)]){
                rm.pb(join(u, i));
            }
        }
        for(auto x: rm){
            auto it = comp.find(x);
            if(it != comp.end()){
                comp.erase(it);
            }
        }
    }
    printf("%d\n", (int)comp.size() - 1);

}