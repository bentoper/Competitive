#include <bits/stdc++.h>
using namespace std;




int main(){
	int n, t;
	int times[100000];
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		cin >> times[i];
	}
	long long int sum = 0, R = 0, ans = 0;
	for(int k = 0; k < n; k++){
        while(R < n && sum + times[R] <= t){
            sum += times[R];
            R++;
        }
        ans = max(ans, (R - k));
        sum -= times[k];
	}
	cout << ans << endl;
}
