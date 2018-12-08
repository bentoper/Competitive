#include <bits/stdc++.h>
using namespace std;

int euclides(long long int a, long long int b){
	return (a%b?euclides(b, a%b):b);
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		long long int a, b;
		cin >> a >> b;
		if(euclides(a, b) != 1){
			cout << "Sim\n";
		}
		else cout << "Nao\n";
	}
}