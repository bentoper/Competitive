//https://www.spoj.com/problems/INVCNT/

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

#define MAXN 11234567

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n, qnt, v[212345];
ll bit[MAXN];

void update(int idx, int val){
	while(idx <= n){
		bit[idx] += val;
		idx += (idx & (-idx));
	}
}

ll sum(int idx){
	ll plc = 0;
	while(idx > 0){
		plc += bit[idx];
		idx -= (idx &-idx);
	}
	return plc;
}

ll rsum(int start, int end){
	return sum(end) - sum(start - 1);
}


int main(){
	rvr(t);
	while(t--){
		
		rvr(qnt);
		
		ll invcount = 0;
		n = 0;

		fr(i, qnt){
			scanf("%d", &v[i]);
			n = max(v[i], n);
		}

		fr(i, n+1) bit[i] = 0;

		fr(i, qnt){
			invcount += rsum(v[i] + 1, n);
			update(v[i], 1);
		}

		printf("%lld\n", invcount);
	}
}
