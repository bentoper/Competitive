//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192

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

#define MAXN 212345

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int bit[MAXN];
int n, clk;

void update(int idx, int val){
	while(idx <= n){
		bit[idx] += val;
		idx += (idx & (-idx));
	}
}

int sum(int idx){
	ll plc = 0;
	while(idx > 0){
		plc += bit[idx];
		idx -= (idx &-idx);
	}
	return plc;
}

int rsum(int start, int end){
	return sum(end) - sum(start - 1);

}

int main(){
	while(scanf("%d", &n) && n != 0){
		if(clk > 0) printf("\n");
		fr(i, n + 1) bit[i] = 0;
		frr(i, n){
			rvr(aux);
			update(i, aux);
		}
		char c;
		printf("Case %d:\n", ++clk);
		while(scanf("%c", &c) && c != 'E'){
			if(c == 'M'){
				int a, b; scanf("%d%d", &a, &b);
				printf("%d\n", rsum(a, b));
			}
			else if(c == 'S'){
				int a, b; scanf("%d%d", &a, &b);
				update(a, b - rsum(a, a));
			}
		}
		fr(i, 2) scanf("%c", &c);
	}

}
