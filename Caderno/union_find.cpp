#include <bits/stdc++.h>
using namespace std;

// par inicializa com p[i] = i e peso = 0, qnt = 1;
int par[N], depth[N];


int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;

}


int main(){

}
