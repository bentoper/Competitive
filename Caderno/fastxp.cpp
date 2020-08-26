#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fastxp(ll x, ll n){
	ll ret = 1;
	while(n){
		if(n&1ll) ret *= x;
		x *= x;
		n>>1ll;
	}
	return ret;
}

int main(){
	
}
