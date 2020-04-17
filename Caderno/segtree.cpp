#include <bits/stdc++.h>
using namespace std;
const int N = 1;

int hi[4*N + 1], lo[4*N + 1], seg[4*N + 1], v[N + 1], lazy[4*N + 1];

int update(int a, int b){
	return OPERACAO;
}

int build(int nd, int start, int end){
	//Start nd value = 1
	lo[nd] = start; hi[nd] = end;

	if(start == end){
		return seg[nd] = v[start];
	}

	int mid = (end+start)/2;

	return seg[nd] = update(build(2*nd, start, mid), build(2*nd + 1, mid + 1, end)); 
}

void unlazy(int nd){

	//Change for what suits the problem

}

int query(int nd, int start, int end){

	unlazy(nd);

	if(hi[nd] < start || lo[nd] > end) return LIXO;
	if(lo[nd] >= start && hi[nd] <= end){
		return seg[nd];
	}

	return update(query(2*nd, start, end), query(2*nd + 1, start, end));

}

void change(int nd, int start, int end, int x){

	unlazy(nd);

	if(hi[nd] < start || lo[nd] > end) return;
	if(lo[nd] >= start && hi[nd] <= end){
		lazy[nd] = x;
		unlazy(nd);
		return;
	}

	change(2*nd, start, end, x);
	change(2*nd+1, start, end, x);

	seg[nd] = update(seg[2*nd], seg[2*nd+1]);
}
int main(){

}
