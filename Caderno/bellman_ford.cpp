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

struct edge{
	int a;
	int b;
	int w;
};

int n, m, dist[MAX], pre[MAX];
vector<edge> edges;

void bf(int root){
	dist[root] = 0;
	int x = - 1;
	for(int i = 0; i < n; i++){
		x = -1;
		for(auto e: edges){
			if(dist[e.a] < INF){
				if(dist[e.b] > dist[e.a] + e.w){
					dist[e.b] = dist[e.a] + e.w;
					x = e.y;
				}
			}
		}
	}
	if(x != -1){
		int y = x;
        for (int i=0; i<n; ++i)
            y = pre[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());
        for (size_t i=0; i<path.size(); ++i)
            dist[path[i]] = INF;
	}
}



int main(){

}
