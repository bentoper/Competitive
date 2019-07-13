#include <bits/stdc++.h>
using namespace std;

#define pb push_back
//#define MAX 1

typedef long long int ll;

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
	int x = -1;
	for(int i = 0; i <= n; i++){
		x = -1;
		for(auto e: edges){
			if(dist[e.a] < INF){
				if(dist[e.b] > dist[e.a] + e.w){
					dist[e.b] = dist[e.a] + e.w;
					x = e.b;
				}
			}
		}
	}
	if(x != -1){
		int y = x;
        for (int i=0; i<n; ++i)
            y = pre[y];

        vector<int> path;
        for (int cur=y; ; cur=pre[cur])
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
