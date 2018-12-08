#include <bits/stdc++.h>
using namespace std;




int main(){
	int n, t;
	int times[100000];
	long long int sum = 0;
	cin >> n >> t;
	int quant = n;
	for(int i = 0; i < n; i++){
		cin >> times[i];
		sum += times[i];
	}
	int i = 0;
	int j = n - 1;
	int maximo;
	while(sum > t && i <= j){
		maximo = max(times[i], times[j]);
		sum -= maximo;
		quant--;
		if(maximo == times[i]) i++;
		else j--;
	}
	if(sum >=0) cout << quant << endl;
	else cout << 0 << endl;
}
