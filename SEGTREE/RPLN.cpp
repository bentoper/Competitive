//https://www.spoj.com/problems/RPLN/

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

const int INF = 1000000001;
const ll llINF = 0x3f3f3f3f3f3f3f;

#define MAXN 1000001


int hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN], lazy[4*MAXN + 1];
int n, q, clk = 1;


int update(int a, int b){
	return min(a, b);
}

int build(int node, int start, int end){
	//dbg(start); dbg(end);

	//Start node value = 1

	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = v[start];
	}

	int mid = end+start;
	mid /= 2;
	//dbg(mid);

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
	seg[node] = (hi[node] - lo[node] + 1)*lazy[node];
	lazy[node] = 0;

}

int query(int node, int start, int end){

	//unlazy(node);

	//printf("stt = %d end = %d lo = %d hi = %d\n", start, end, lo[node], hi[node]);	

	if(hi[node] < start || lo[node] > end) return INF;
	if(hi[node] <= end && lo[node] >= start){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));
	
}

void change(int node, int start, int end, int x){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		lazy[node] = x;
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);
}


int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> q;
		frr(i, n) cin >> v[i];
		build(1, 1, n);
		printf("Scenario #%d:\n", clk++);
		fr(i, q){
			int a, b; cin >> a >> b;
			cout << query(1, a, b) << endl;
		}
	}

}
