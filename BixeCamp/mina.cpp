#include <bits/stdc++.h>
using namespace std;

int dist[100][100], w[100][100], visited[100][100], N;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void bfs(int x, int y){
    priority_queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, 0)));
    dist[x][y] = 0;
    while(!q.empty()){
            pair<int, int> v = q.top().second;
            q.pop();
            if(visited[v.first][v.second]) continue;
            visited[v.first][v.second] = 1;
            for(int i = 0; i < 4; i++){
                int nx = v.first + dx[i];
                int ny = v.second + dy[i];
                if(nx >= N || ny >= N || nx < 0 || ny < 0) continue;
                if(dist[nx][ny] > dist[v.first][v.second] + w[nx][ny]){
                    dist[nx][ny] = dist[v.first][v.second] + w[nx][ny];
                    q.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
                }
            }
    }
    return;
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = 1000000000;
            cin >> w[i][j];
        }
    }
    bfs(0, 0);
    cout << dist[N-1][N-1] << endl;
}
