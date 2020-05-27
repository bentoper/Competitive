//https://www.spoj.com/problems/HORRIBLE/
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

#define MAXN 1000001


ll hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], lazy[4*MAXN + 1];
int n, q;



ll update(ll a, ll b){
	return a + b;
}

int build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = 0;
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 

}

void unlazy(int node){

	//Change for what suits the problem

	if(hi[node] == lo[node]){
		seg[node] += lazy[node];
		lazy[node] = 0;
		return;
	}

	lazy[2*node] += lazy[node];
	lazy[2*node + 1] += lazy[node];
	seg[node] += (hi[node] - lo[node] + 1)*lazy[node];
	lazy[node] = 0;

}

ll query(int node, int start, int end){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return 0;
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, int x){

	unlazy(node);

	//printf("stt = %d end = %d lo = %d hi = %d\n", start, end, lo[node], hi[node]);

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
	int t; cin >> t;
	while(t--){
		cin >> n >> q;
		build(1, 1, n);
		ms(lazy, 0);
		fr(i, q){
			int mode, a, b;
			cin >> mode >> a >> b;
			if(!mode){
				int v; cin >> v;
				change(1, a, b, v);
				//printf("VACA\n");
			}
			else{
				cout << query(1, a, b) << endl;
			}
		}

	}

}
