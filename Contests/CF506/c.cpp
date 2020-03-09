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
#define f first
#define s second
 
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

int l[N], r[N];
int n;

pii suf[N], pref[N];

int main(){
	scanf("%d", &n);
	if(n == 1){
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", b - a);
		return 0;
	}
	pii cur = mp(-INF, INF);
	fr(i, n){
		scanf("%d%d", &l[i], &r[i]);
		cur.first = max(l[i], cur.first);
		cur.second = min(r[i], cur.second);
		pref[i] = cur;
	}
	cur = mp(-INF, INF);
	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		cur.first = max(l[i], cur.first);
		cur.second = min(r[i], cur.second);
		suf[i] = cur;
		if(i == n - 1){
			pii plc = pref[n-2];
			if(plc.s < plc.f) continue;
			else ans = max(ans, plc.s - plc.f); 
		}	
		else if(i != 0){
			pii plc = suf[i + 1], plc1 = pref[i-1];
			pii res;
			res.first = max(plc.f, plc1.f);
			res.second = min(plc.s, plc1.s);
			if(res.first <= res.second) ans = max(ans, res.s - res.f);
		}
		else if(suf[1].s >= suf[1].f) ans = max(suf[1].s - suf[1].f, ans);
	}
	printf("%d\n", ans);
}