#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b, c, o = 0;
	cin >> n >> a >> b >> c;
	if(n%min(min(a,b),c) == 0){
	    cout << n/min(min(a,b),c);
	    return 0;
	}
	for(int k1 = 0; k1 <= n/a; k1++){
	    for(int k2 = 0; k2 <= (n-k1*a)/b; k2++){
	        int k3 = (n - k1*a - k2*b)/c;
	        int s = k1*a+k2*b+k3*c;
	        int r = k1+k2+k3;
	        if(s != 0){
	            if(n%s == 0){
	                o = max(r,o);
	            }
	        }
	    }
	}
    cout << o << endl;
}
