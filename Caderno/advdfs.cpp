#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define MAXN 1

typedef long long int ll;

typedef vector<int> vi;

int clk = 0;

int low[MAXN], pre[MAXN], qnt = 0, numSCC;

stack<int> eds, nodes;

bool art[MAXN], used[2*MAXN];

struct Edges{
	int x, y, id;
};

vi bridges, comps[MAXN];

vector<Edges> edges[MAXN];

void makecomp(int id){
	while(eds.top() != id){
		comps[qnt].pb(eds.top());
		eds.pop();
	}
	if(id != -1) comps[qnt++].pb(id);
	eds.pop();
}


int dfs(int v, int p, int id){
	

	if(id == -1 || !used[id]){
		eds.push(id);
		used[id] = true;
	}

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];
	bool forw = false;
	for(auto e: edges[v]){
		int x = e.y;
		if(e.id == id) continue;
		if(pre[x] == -1){
			dfs(x, v, e.id);
			low[v] = min(low[v], low[x]);
			if(pre[x] == low[x]){
				bridges.pb(e.id);
			}
			if(v != p ? low[x] >= pre[v] : forw){
				art[v] = true;
				makecomp(e.id);
			}
			forw = true;
		}
		else low[v] = min(low[v], pre[x]);
	}

	if(low[v] == pre[v]){
		while(true){
			int j = nodes.top();
			nodes.pop();
			id[j] = numSCC;
			low[j] = MAXN;
			if(j == v) break;
		}
		numSCC++;
	}

}

int main(){

}
