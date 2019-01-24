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
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll n, m, k;
ll nums[100001];
ll accu[100002];
ll freq[100002];
vector<pair<pii, int>> ops;


int main(){
	cin >> n >> m >> k;
	frr(i, n){
		cin >> nums[i];
	}
	ops.pb({{0, 0}, 0});
	fr(i, m){
		rvr(aux1); rvr(aux2); rvr(aux3);
		ops.pb({{aux1, aux2}, aux3});
	}
	fr(i, k){
		rvr(aux1); rvr(aux2);
		freq[aux1]++;
		freq[aux2+1]--;
	}
	frr(i, m){
		freq[i] += freq[i-1];
		accu[ops[i].first.first] += (ll)(freq[i]*(ll)ops[i].snd);
		accu[ops[i].first.snd+1] -= (ll)(freq[i]*(ll)ops[i].snd);
	}
	frr(i, n){
		accu[i] += accu[i-1];
	}
	frr(i, n){
		ll aux = nums[i] + accu[i];
		cout << aux << " ";
	}
	gnl;
}
