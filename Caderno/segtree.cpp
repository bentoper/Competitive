#include <bits/stdc++.h>
using namespace std;

int hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN + 1], lazy[4*MAXN + 1];


int update(int a, int b){
	return OPERACAO;
}

int build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = v[start];
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 

}

void unlazy(int node){

	//Change for what suits the problem

	if(hi[node] == lo[node]){
		seg[node] += lazy[node];
		lazy[node] = 0;
		return;
	}

	lazy[2*node] += lazy[node];
	lazy[2*node + 1] += lazy[node];
	seg[node] = (hi[node] - lo[node] + 1)*lazy[node];
	lazy[node] = 0;

}

int query(int node, int start, int end){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return LIXO;
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, int x){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		lazy[node] = x;
		unlazy(node);
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}


int main(){

}
