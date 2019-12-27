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
#define lll(x) 2*x
#define rr(x) 2*x + 1


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int N = 212345;
const ll INF = (ll)N*(ll)N*ll(N);


int hi[4*N + 1], lo[4*N +1], a[N+1];
ll seg[4*N + 1], lazy[4*N + 1], v[N+1];

ll build(int node, int s, int e){
	hi[node] = e;
	lo[node] = s;
	if(s == e){
		seg[node] = v[s];
		return seg[node];
	}
	int mid = (s + e)/2;

	return seg[node] = min(build(lll(node), s, mid), build(rr(node), mid+1, e));
}


void unlazy(int node){
	seg[node] += lazy[node];
	if(hi[node] != lo[node]){
		lazy[lll(node)] += lazy[node];
		lazy[rr(node)] += lazy[node];
	}
	lazy[node] = 0;
}

ll query(int node, int s, int e){

	unlazy(node);

	if(s > hi[node] || e < lo[node]) return INF;
	if(lo[node] >= s && hi[node] <= e) return seg[node];
	return min(query(lll(node), s, e), query(rr(node), s, e));

}

ll change(int node, int s, int e, ll x){

	unlazy(node);

	if(s > hi[node] || e < lo[node]) return seg[node];
	if(lo[node] >= s && hi[node] <= e){
		lazy[node] += x;
		unlazy(node);
		return seg[node];
	}
	return seg[node] = min(change(lll(node), s, e, x), change(rr(node), s, e, x));
}

int pos(int node){
	if(hi[node] == lo[node]) return hi[node];
	ll lq = query(lll(node), lo[lll(node)], hi[lll(node)]), rq = query(rr(node), lo[rr(node)], hi[rr(node)]);
	if(rq <= lq) return pos(rr(node));
	return pos(lll(node));
}

int main(){
	int n; scanf("%d", &n);
	frr(i, n) scanf("%lld", &v[i]);
	build(1, 1, n);
	frr(i, n){
		int pp = pos(1);
		a[pp] = i;
		change(1, pp, pp, INF);
		if(pp < n) change(1, pp+1, n, -i);
	}
	frr(i, n) printf("%d%c", a[i], " \n"[i==n]);
}