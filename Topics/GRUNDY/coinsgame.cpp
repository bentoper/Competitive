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


int v[1000001], K, L, m;

int dp(int left){
	if(v[left] == -1){
		if(left - K >= 0 and dp(left - K) == 0) v[left] = 1;
		else if(left - L >= 0 and dp(left - L) == 0) v[left] = 1;
		else if(left - 1 >= 0 and dp(left - 1) == 0) v[left] = 1;
		else v[left] = 0;
	}
	return v[left];
}





int main(){
	scanf("%d%d%d", &K, &L, &m);
	ms(v, -1);
	v[0] = 0;
	v[1] = v[K] = v[L] = 1;
	fr(i, m){
		rvr(aux);
		if(dp(aux) == 1) printf("A");
		else printf("B");
	}
	gnl;
}
