#include <bits/stdc++.h>
using namespace std;

int a[212345];

int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 1;
	int i = 0;
	while(i < n){
		int cur = a[i], sz = 1;
		while(i + 1 < n && a[i + 1] <= 2*cur){
			cur = a[i+1];
			sz++;
			i++;
		}
		i++;
		ans = max(ans, sz);
	}
	printf("%d\n", ans);
}