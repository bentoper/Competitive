#include <bits/stdc++.h>
using namespace std;
const int N = 1;

typedef vector<int> vi;

template <class T>
class SegTree{
	public:
	vector<T> seg, lazy;
	vi v, hi, lo;
	function<T(T, T)> upd;
	function<void(vi&, vi&, vector<T>&, vector<T>&, int)> unlzy;
	T LIXO;

	SegTree(int n, T lx, vector<T>& vec, const function<T(T, T)>& updt, 
		const function<void(vi&, vi&, vector<T>&, vector<T>&, int)>& U)
	{
		v = vec, upd = updt, unlzy = U;
		hi.resize(4*n + 1), lo.resize(4*n + 1),	seg.resize(4*n + 1), lazy.resize(4*n + 1);
		LIXO = lx;
		build(1, 0, n-1);
	}

	T update(T a, T b){
		return upd(a, b);
	}

	T build(int nd, int start, int end){
		lo[nd] = start; hi[nd] = end;
		if(start == end){
			seg[nd] = v[start];
			return seg[nd];
		}
		int mid = (end+start)/2;
		seg[nd] = update(build(2*nd, start, mid), build(2*nd + 1, mid + 1, end)); 
		return seg[nd];
	}

	void unlazy(int nd){
		unlzy(hi, lo, seg, lazy, nd);
	}

	T query(int nd, int start, int end){
		unlazy(nd);
	
		if(hi[nd] < start || lo[nd] > end) return LIXO;
		if(lo[nd] >= start && hi[nd] <= end){
			return seg[nd];
		}
		return update(query(2*nd, start, end), query(2*nd + 1, start, end));
	}

	void change(int nd, int start, int end, T x){
		unlazy(nd);
		if(hi[nd] < start || lo[nd] > end) return;
		if(lo[nd] >= start && hi[nd] <= end){
			lazy[nd] = x;
			unlazy(nd);
			return;
		}
		change(2*nd, start, end, x);
		change(2*nd+1, start, end, x);
		seg[nd] = update(seg[2*nd], seg[2*nd+1]);
	}
};

int main(){
	
}
