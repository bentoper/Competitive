#include <bits/stdc++.h>
using namespace std;

int people[102][102], N, I, J, out, flags[102][102];

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void passabolinha(int a, int b, int passou1, int passou2){
    flags[a][b] = 1;
    for(int i = 0; i < 4; i++){
        int x = a + dx[i];
        int y = b + dy[i];
        if(people[x][y] >= people[a][b] && (flags[x][y] == 0)){
            passabolinha(x, y, a, b);
        }
    }
    out++;
    return;
}


int main(){
    cin >> N >> I >> J;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> people[i][j];
        }
    }
    passabolinha(I, J, 0, 0);
    cout << out << endl;
}
