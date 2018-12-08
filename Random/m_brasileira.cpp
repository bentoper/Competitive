#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int last = 0, otp = n;
	for(int i = 0; i < n; i++){
		int aux; cin >> aux;
		if(i != 0 && last >= aux) otp--;
		last = aux;
	}
	cout << otp << endl;
}