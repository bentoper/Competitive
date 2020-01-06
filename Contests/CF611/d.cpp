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
const int N = 2e5 + 10;

int n, m;
int x[N];
ll d = 0;
set<pii> dist;
map<int, bool> vis;
vi ans;

void bfs(){
    queue<pii> q;
    fr(i, n){
        q.push(mp(x[i], 0));
        vis[x[i]] = true;
    }
    while(ans.size() < m && !q.empty()){
        pii a = q.front();
        q.pop();
        int pos = a.first, dist = a.second;
        if(!vis[pos + 1]){
            vis[pos+1] = true;
            q.push(mp(pos+1, dist+1));
        }
        if(!vis[pos - 1]){
            vis[pos-1] = true;
            q.push(mp(pos-1, dist+1));
        }
        if(dist != 0){
            ans.pb(pos);
            d += (ll)dist;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    fr(i, n) scanf("%d", &x[i]);
    bfs();
    printf("%lld\n", d);
    pv(ans, m);
}