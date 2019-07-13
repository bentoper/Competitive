#include <bits/stdc++.h>
using namespace std;
// O(N) complexity (don't really know why) - thanks to nonseq
#define pb push_back
//#define MAX_SIEVE 1000000

vector<int> prim;
int mark[MAX_SIEVE];
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i);
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}


int main(){
	
}
