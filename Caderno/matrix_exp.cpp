/*
	Modified code for matrix exponentiation to account for large numbers,
	with better tools for handling modular arithmetic.
	Original can be found here: https://github.com/splucs/Competitive-Programming/blob/master/Macac%C3%A1rio/Math/matrixexp.cpp
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<vector<ll>> matrix;

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<ll>(p));
	ll col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j];
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++){
				ll aux = a[i][k] * col[k];
				s = s + aux;

			}
			c[i][j] = s;
		}
	}
	return c;
}

matrix id(ll n) {
	matrix c(n, vector<ll>(n));
	for(int i = 0; i < n; i++) c[i][i] = 1;
	return c;
}

matrix matrixExp(matrix a, int n) {
	if (n == 0) return id(a.size());
	matrix c = matrixExp(a, n/2);
	c = c*c;
	if (n%2 != 0) c = c*a;
	return c;
}


int main() {
	
}
