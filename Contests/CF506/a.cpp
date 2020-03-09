#include <bits/stdc++.h>
using namespace std;


int main(){
	string s, t; int n , k;
	cin >> n >> k >> s;
	t = s;
	int ans = 0, pos = -1;
	for(int i = 1; i <= n - 1; i++){
		int j = n - 1, ini = i - 1;
		while(ini >= 0 && s[ini] == s[j]) j--, ini--;
		if(ini == -1){
			ans = i;
		} 
	}
	if(ans == 0){
		for(int i = 0; i < k; i++) cout << s;
		cout << endl;
		return 0;
	}
	string plc = s.substr(ans, n - ans);
	cout << s;
	for(int i = 0; i < k - 1; i++) cout << plc;
	cout << endl;
}