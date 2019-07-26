#include <bits/stdc++.h>
using namespace std;

// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[MAX], peso[MAX], qnt[MAX];


int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(peso[x] > peso[y]) swap(x, y);

	pai[x] = y;
	if(peso[x] == peso[y]) peso[y]++;
	qnt[y] += qnt[x];

}


int main(){

}
