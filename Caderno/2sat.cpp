#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAXN 2 //twice amount of stuff

int clk = 0, qnt = 0;

int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

bool eval[MAXN];

vector<int> adj[MAXN];

stack<int> nodes;

int dfs(int v){

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];
	for(auto x: adj[v]){
		if(pre[x] == -1){
			dfs(x);
			low[v] = min(low[v], low[x]);
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

int neg(int i){
	return i + ((i > qnt)?qnt:-qnt); 
}


void add_imp(int i, int j){
	adj[i].pb(j);
}

void add_or(int i, int j){
	add_imp(neg(i), j);
	add_imp(neg(j), i);
}

void add_xor(int i, int j){
	add_or(i, j);
	add_or(neg(i), neg(j));
}

bool sat(){
	for(int i = 1; i<= 2*qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 1; i <= qnt; i++){
		if(id[i] == id[neg(i)]) return false;
		eval[i] = id[i] > id[neg(i)];
		eval[neg(i)] = !eval[i];
	}

	return true;
}

int main(){

}