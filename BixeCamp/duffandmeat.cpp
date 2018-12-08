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

int cost[100001], required[100001], n;

int main(){
	scanf("%d", &n);
	frr(i, n){
		scanf("%d %d", &required[i], &cost[i]);
	}
	ll out = 0; int j = 1;
	while(j <= n){
		int buy = 0; int price = cost[j];
		while(j <= n && price <= cost[j]){
			buy += required[j];
			j++;
		}
		out += ((ll) price * (ll) buy);
	}
	otp(out);
}
