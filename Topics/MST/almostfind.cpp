#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


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
const int N = 3e5 + 1;

int par[N], depth[N], id[N], idd, qnt[N];

ll sum[N];

int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;
	sum[y] += sum[x];
	qnt[y] += qnt[x];
}

int n, m;

int main(){
	while(scanf("%d%d", &n, &m) == 2){
		idd = n + 1;
		frr(i, n) par[i] = i, depth[i] = 0, sum[i] = i, id[i] = i, qnt[i] = 1;
		fr(i, m){
			rvr(q);
			if(q == 1 || q == 2){
				int a, b; scanf("%d%d", &a, &b);
				if(q == 1) join(id[a], id[b]);
				else{
					if(find(id[a]) == find(id[b])) continue;
					sum[find(id[a])] -= (ll)a;
					qnt[find(id[a])]--;
					id[a] = idd++;
					qnt[id[a]] = 1;
					par[id[a]] = id[a];
					sum[id[a]] = a;
					join(id[a], id[b]);
				}
			}
			else{
				rvr(a);
				printf("%d %lld\n", qnt[find(id[a])], sum[find(id[a])]);
			}
		}
	}
}