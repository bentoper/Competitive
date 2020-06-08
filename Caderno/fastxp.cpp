#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fastxp(ll a, int x, int mod){
	if(x == 0) return 1;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2, mod)*((x&1)?a:1))%mod;
}

int main(){
	
}
