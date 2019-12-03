//Tree Uniondiv2 topcoder
#include <bits/stdc++.h>
using namespace std;

int dist[19][19], n;

void dfs(int r, int p, int v, vector<string> tree, int h){
    dist[r][v] = h;
    dist[v][r] = h;
    for(int i = 0; i < n; i++){
        if(i + n*(r >= n) != p && tree[v%n][i] == 'X'){
            dfs(r, v, i + n*(r >= n), tree, h + 1);
        }
    }
}


class TreeUnionDiv2{
	
    public:
    
    int maximumCycles(vector<string> tree1, vector<string> tree2, int K){
    	n = tree1[0].size();
        int perm[n], ans = 0, plc;
        for(int i = 0; i < n; i++){
            dfs(i, i, i, tree1, 0);
            perm[i] = i;
        }
        for(int i = n; i < 2*n; i++){
            dfs(i, i, i, tree2, 0);
        }
        do{
            plc = 0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    int sz = 2 + dist[i][j] + dist[perm[i] + n][perm[j] + n];
                    if(sz == K) plc++;
                }
            }
            ans = max(plc, ans);

        }while(next_permutation(perm, perm+n));

        return ans;
    }
    
};