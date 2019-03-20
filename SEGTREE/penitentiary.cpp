//https://codeforces.com/gym/101879/problem/G

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const pii LIXO = {1, 0};

#define MAXN 200001


int hi[4*MAXN + 1], lo[4*MAXN + 1], lazy[4*MAXN + 1];
pii v[MAXN + 1], seg[4*MAXN + 1];

int n, q;


pii update(pii a, pii b){

	if(a == LIXO || b == LIXO) return LIXO;

	if(a.first > b.snd  || b.first > a.snd) return LIXO;

	if(b.first < a.first) swap(a, b);

	if(a.snd > b.snd) return b;

	return {b.first, a.second};
	
}

pii build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = v[start];
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 

}

/*void unlazy(int node){

	//Change for what suits the problem

	if(hi[node] == lo[node]){
		seg[node] += lazy[node];
		lazy[node] = 0;
		return;
	}

	lazy[2*node] += lazy[node];
	lazy[2*node + 1] += lazy[node];
	seg[node] = (hi[node] - lo[node] + 1)*lazy[node];
	lazy[node] = 0;

}*/

pii query(int node, int start, int end){

	if(hi[node] < start || lo[node] > end) return {-1000000000, 1000000000};
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, pii x){


	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		seg[node] = x;
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}


int main(){

	fastio;
	cin >> n >> q;
	frr(i, n){
		int a, b; cin >> a >> b;
		v[i] = {a, b};
	}

	build(1, 1, n);

	fr(i, q){
		char c; cin >> c;
		if(c == 'C'){
			int node, a, b; cin >> node >> a >> b;
			change(1, node, node, {a, b});
		}
		else{
			int a, b; cin >> a >> b;
			pii placeholder = query(1, a, b);
			if(placeholder == LIXO){
				cout << 0 << endl;
			}
			else{
				cout << placeholder.snd - placeholder.first + 1 << endl;
			}
		}
	}

}
