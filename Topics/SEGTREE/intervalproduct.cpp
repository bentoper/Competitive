// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3977

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


int hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN + 1], lazy[4*MAXN + 1];
int n, k;

string ans = "";


int update(int a, int b){
	return b*a;
}

int build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		if(v[start] < 0) seg[node] = -1;
		else if(v[start] > 0) seg[node] = 1;
		else seg[node] = 0;
		return seg[node];
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
	seg[node] = (hi[node] - lo[node] + 1)*lazy[node];
	lazy[node] = 0;

}

int query(int node, int start, int end){

	//unlazy(node);

	if(hi[node] < start || lo[node] > end) return 1;
	if(hi[node] <= end && lo[node] >= start){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

int change(int node, int start, int end, int x){

	//unlazy(node);

	if(hi[node] < start || lo[node] > end) return seg[node];
	if(hi[node] <= end && lo[node] >= start){
		if(x < 0) seg[node] = -1;
		else if(x > 0) seg[node] = 1;
		else seg[node] = 0;
		return seg[node];
	}

	return seg[node] = update(change(2*node, start, end, x), change(2*node+1, start, end, x));
}


int main(){
	while(scanf("%d%d", &n, &k) == 2){
		ans = "";
		frr(i, n) cin >> v[i];
		build(1, 1, n);
		fr(i, k){
			char c; cin >> c;
			int a, b; cin >> a >> b;
			if(c == 'C'){
				change(1, a, a, b);
			}
			else{
				int q = query(1, a, b);
				if(q < 0) ans.pb('-');
				else if(q > 0) ans.pb('+');
				else ans.pb('0');
			}
		}
		cout << ans << endl;
	}
}
