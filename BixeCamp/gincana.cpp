#include <bits/stdc++.h>
using namespace std;

int N, M, flag[1000], c;
vector<int> pares[1000];

void dfs(int a){
    flag[a] = 1;
    for(int i = 0; i < pares[a].size(); i++){
        if(flag[pares[a][i]] == 0){
            dfs(pares[a][i]);
        }
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int I, J;
        cin >> I >> J;
        pares[I-1].push_back(J-1);
        pares[J-1].push_back(I-1);
    }
    for(int i = 0; i < N; i++){
        if(flag[i] == 0){
            dfs(i);
            c++;
        }
    }
    cout << c << endl;
}
