//https://www.urionlinejudge.com.br/judge/en/problems/view/2658
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

#define MAXN 100001


struct no{
	int grt = 0;
	int freq[9] = {0};
};



int hi[4*MAXN + 1], lo[4*MAXN + 1], v[MAXN + 1];

ll lazy[4*MAXN + 1];

no seg[4*MAXN + 1];

int n, q;


no update(no a, no b){

	if(a.grt == -1) return b;
	if(b.grt == -1) return a;

	no placeholder;
	
	int max = 0; 

	fr(i, 9){
		placeholder.freq[i] = a.freq[i] + b.freq[i];
		if(placeholder.freq[i] >= max){
			 placeholder.grt = i;
			 max = placeholder.freq[i];
		}
	}

	return placeholder;
}


no build(int node, int start, int end){

	//dbg(start); dbg(end); dbg(node);

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		v[start] = 1;
		seg[node].freq[1] = 1;
		seg[node].grt = 1;
		return seg[node];
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 

}

void unlazy(int node){

	if(lazy[node] == 0) return;

	//Change for what suits the problem

	

	if(hi[node] == lo[node]){
		int i;
		for(i = 0; i < 9; i++) if(seg[node].freq[i] != 0) break;
		int placeholder = (i+lazy[node])%9;
		seg[node].freq[placeholder] = 1;	
		seg[node].freq[i] = 0;
		v[lo[node]] = placeholder;
		lazy[node] = 0;
		return;
	}



	lazy[2*node] += lazy[node];
	lazy[2*node + 1] += lazy[node];

	int placeholder[9];

	for(ll i = 0; i < 9; i++){
		placeholder[(i+lazy[node])%9] = seg[node].freq[i]; 
	}
	copy(placeholder, placeholder+9, seg[node].freq);
	seg[node].grt += lazy[node];
	seg[node].grt %= 9;
	lazy[node] = 0;
}

no query(int node, int start, int end){

	unlazy(node);

	if(hi[node] < start || lo[node] > end){
		no placeholder;
		placeholder.grt = -1;
		return placeholder;
	}
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, int x){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		lazy[node] += x;
		unlazy(node);
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}


int main(){

	fastio;

	cin >> n >> q;
	build(1, 0, n-1);

	fr(i, q){

		int a, b; cin >> a >> b;

		no ans = query(1, a, b);

		change(1, a, b, ans.grt);

	}

	fr(i, n){
		change(1, i, i, 0);
		cout << v[i] << endl;
	}
}