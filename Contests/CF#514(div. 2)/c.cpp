#include "bits/stdc++.h"
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
#define gnl printf("\n");
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi out;

int main(){
	rvr(n);
	if(n == 3){
		cout << "1 1 3" << endl;
		return 0;
	}
	for(int i = 1; i <= n; i *=2){
		for(int j = i; j <= n; j += 2*i){
			out.pb(i);
		}
	}
	sort(all(out));
	if(n%2 == 0 and n%3 == 0){
		out[out.size() - 1] = n;
		out[out.size() - 2] = out[out.size() - 3];
	}
	fr(i, out.size()){
		printf("%d ", out[i]);
	}
	gnl;
}
