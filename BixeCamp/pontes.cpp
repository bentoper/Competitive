#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

vector<int> adj[1002];
int w[1002][1002], visited[1002], dist[1002];

void dijkstra(int start){
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    dist[start] = 0;
    while(!q.empty()){
            int v = q.top().second;
            q.pop();
            if(visited[v]) continue;
            visited[v] = 1;
            for(int u: adj[v]){
                if(dist[u] > dist[v] + w[u][v]){
                    dist[u] = dist[v] + w[u][v];
                    q.push(make_pair(-dist[u], u));
                }
            }
    }
    return;
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i <= N+1; i++){
        dist[i] = INF;
    }
    for(int i = 0; i < M; i++){
        int S, T, B;
        cin >> S >> T >> B;
        w[S][T] = B;
        w[T][S] = B;
        adj[S].push_back(T);
        adj[T].push_back(S);
    }
    dijkstra(0);
    cout << dist[N+1] << endl;
}
