#include <bits/stdc++.h>
using namespace std;

//copiei do Guidi
/*#define MAXN 	100100
#define LMAXN	20*/		//ceil(log2(MAXN))

vector<int> adj[MAXN];

int memo[MAXN][LMAXN + 1];
int hgt[MAXN];
int n;

void dfslca(int v){
	
	for(auto filho : adj[v]){
	
		if(hgt[filho] != -1) continue;
	
		memo[filho][0]=v;
		hgt[filho]=hgt[v]+1;
		
		for(int i=1;i<LMAXN;i++) if(memo[filho][i-1] != -1) memo[filho][i]=memo[memo[filho][i-1]][i-1];
		dfslca(filho);
	}

}

int lca(int a, int b){

	if(hgt[a]<hgt[b]) swap(a,b);

	for(int i=LMAXN-1; i>=0; i-- ){
		if(memo[a][i] != -1 && hgt[ memo[a][i] ] >= hgt[b])	a=memo[a][i];
	}

	if(a==b)	return a;

	for(int i=LMAXN-1; i>=0; i--){
		if(memo[a][i] == -1 || memo[a][i] == memo[b][i]) continue;
		a=memo[a][i];
		b=memo[b][i];
	}

	return memo[b][0];

}

Int main(){

}