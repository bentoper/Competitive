#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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
const int MAXN = 5123;

int n, m, k;

int a[MAXN], b[MAXN], c[MAXN], l[MAXN], pos[MAXN];

int hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN + 1], lazy[4*MAXN + 1];


bool mysort(int a, int b){
    if(c[b] > c[a]) return 0;
    if(c[b] == c[a] && b > a) return 0;
    return 1;
}

int update(int a, int b){
	return min(a, b);
}

int build(int node, int start, int end){

	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = v[start];
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
	seg[node] += lazy[node];
	lazy[node] = 0;

}

int query(int node, int start, int end){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return INF;
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, int x){

	unlazy(node);

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
		lazy[node] = x;
		unlazy(node);
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    int ss = k;
    bool deu = true;
    frr(i, n){
        l[i] = i;
        pos[i] = i;
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        if(ss < a[i]) deu = false;
        ss += b[i];
    }
    if(!deu){
        printf("-1\n");
        return 0;
    }
    int mn = INF;
    v[n+1] = ss;
    for(int i = n; i >= 0; i--){
        ss -= b[i];
        v[i] = min(mn, ss - a[i]);
        mn = min(mn, v[i]);
    }
    build(1, 1, n+1);

    fr(i, m){
        int u, vv; scanf("%d%d", &u, &vv);
        if(u > l[vv]) l[vv] = u;
    }

    //pv(v, n+2);
    sort(pos+1, pos+n+1, mysort);
    //pv(pos, n+1);

    ll ans = 0;

    frr(i, n){
        int vv = pos[i];
        //printf("l[%d] = %d\n", vv, l[vv]);
        int qq = query(1, l[vv]+1, n+1);
        if(qq > 0){
            ans += c[vv];
            change(1, l[vv]+1, n+1, -1);
        }
    }

    printf("%lld\n", ans);

}
