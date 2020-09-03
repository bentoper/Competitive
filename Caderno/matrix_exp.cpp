#include <bits/stdc++.h>
using namespace std;

template <class T> 
class Matrix{
	public:
	int n, m;
	vector<vector<T>> v;
	T lx;
	Matrix(int nn, int mm, T lxx){
		n = nn, m = mm, lx = lxx;
		v.resize(n);
		for(int i = 0; i < n; i++) v[i] = vector<T>(mm, lxx);
	}
	
	vector<T>& operator[](int i){
		return v[i];
	}
	
	Matrix id(int n) {
		Matrix c(n, n, (*this).lx);
		for(int i = 0; i < n; i++) c[i][i] = 1;
		return c;
	}

	Matrix operator*(Matrix b){
		int n = (*this).n, m = b.n, p = b.m;
		Matrix<T> c(n, p, (*this).lx);
		T col[m];
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++)
				col[k] = b[k][j];
			for (int i = 0; i < n; i++) {
				T s = 0;
				for (int k = 0; k < m; k++){
					T aux = (*this)[i][k] * col[k];
					s = s + aux;

				}
				c[i][j] = s;
			}
		}
		return c;
	}
	
	void xp(long long int n) {
		Matrix<T> c(0, 0, lx);
		c = *this;
		n--;
		while(n > 0){
			if(n&1ll){
				(*this) = (*this)*c;
			}
			n /= 2ll;
			c = c*c;
		}
	}
};

int main(){
	
}
