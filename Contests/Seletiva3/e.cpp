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
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 112345

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n, m;


ll hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN + 1], lazy[4*MAXN + 1];

ll segmx[4*MAXN+1], segmn[4*MAXN + 1];


ll update(ll a, ll b){
	return a+b;
}

void unlazy(int node){

	ll l = lo[node], r = hi[node];

	ll csi = lazy[node];

	if(l != r){
		lazy[2*node] = csi;
		lazy[2*node + 1] = csi;
	}
	
	seg[node] = (r - l + 1)*csi;
	segmx[node]  = csi;
	segmn[node] = csi;
	lazy[node] = -1; 
}

ll build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		
		segmx[node] = segmn[node] = v[start];
		lazy[node] = -1;
		return seg[node] = v[start];
	}

	int mid = (end+start)/2;

	seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 
	segmx[node] = max(segmx[2*node], segmx[2*node+1]);
	segmn[node] = min(segmn[2*node], segmn[2*node+1]);
	lazy[node] = -1;
	return seg[node];
}

ll query(int node, int start, int end){

	if(lazy[node] != -1) unlazy(node);

	if(hi[node] < start || lo[node] > end) return 0;
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change1(int node, int start, int end, int x){

	if(lazy[node] != -1) unlazy(node);

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		seg[node] = x;
		segmx[node] = x;
		segmn[node] = x;
		return;
	}

	change1(2*node, start, end, x);
	change1(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
	segmx[node] = max(segmx[2*node], segmx[2*node+1]);
	segmn[node] = min(segmn[2*node], segmn[2*node+1]);
}

void change2(int node, int start, int end, ll x){

	if(lazy[node] != -1) unlazy(node);

	if(hi[node] < start || lo[node] > end || segmx[node] < x) return;
	
	if(lo[node] >= start && hi[node] <= end && segmx[node] == segmn[node]){
		lazy[node] = segmn[node]%x;
		unlazy(node);
		return;
	}
	else{
		change2(2*node, start, end, x);
		change2(2*node+1, start, end, x);
		seg[node] = update(seg[2*node], seg[2*node+1]);
		segmx[node] = max(segmx[2*node], segmx[2*node+1]);
		segmn[node] = min(segmn[2*node], segmn[2*node+1]);
	}
} 


int main(){
	scanf("%d%d", &n, &m);
	frr(i, n){
		scanf("%lld", &v[i]);
	}
	build(1, 1, n);
	while(m--){
		int a; scanf("%d", &a);
		if(a == 1){
			int b, c; scanf("%d%d", &b, &c);
			printf("%lld\n", query(1, b, c));
		}
		else if(a == 2){

			ll x;
			int b, c; scanf("%d%d%lld", &b, &c, &x);
			change2(1, b, c, x);
		}
		else{
			ll x;
			int b; scanf("%d%lld", &b, &x);
			change1(1, b, b, x);
		}
	}

}

