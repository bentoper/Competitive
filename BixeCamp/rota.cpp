#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define pq priority_queue
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int N, M, C, K, w[250][250], visited[250], dist[250];
vi adj[250];

void dijkstra(){
    pq<pii> q;
    q.push(mp(0, K));
    dist[K] = 0;
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(visited[v]) continue;
        visited[v] = 1;
        for(int u: adj[v]){
            if(v <= C - 1 && u != v + 1) continue;
            if(dist[u] > dist[v] + w[v][u]){
                dist[u] = dist[v] + w[v][u];
                q.push(mp(-dist[u], u));
            }
        }
    }
}

int main(){
    cin >> N >> M >> C >> K;
    while(!(N == 0 and M == 0 and C == 0 and K == 0)){
        fr(i, M){
            int U, V, P;
            cin >> U >> V >> P;
            adj[U].push_back(V);
            adj[V].push_back(U);
            w[U][V] = P;
            w[V][U] = P;
        }
        fr(i, 250) dist[i] = INF;
        dijkstra();
        cout << dist[C-1] << endl;
        fr(i, N){
            adj[i].clear();
            dist[i] = INF;
            visited[i] = 0;
            fr(j, N) w[i][j] = 0;
        }
        cin >> N >> M >> C >> K;
    }
}
