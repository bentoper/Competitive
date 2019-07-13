#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


//Requires a vector of prime numbers "prim"

ll tot(ll x){
	ll ans = x;
	for(auto z: prim){
		if(z*z > x) break;
		if(x%z == 0){
			while(x%z == 0){
				x /= z;
			}
			ans -= ans/z;
		}
	}
	if(x != 1) ans -= ans/x;
	return ans;
}


int main(){

}
