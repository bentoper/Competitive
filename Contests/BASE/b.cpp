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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


int cnt = 10;
bool used[10];


void solve(ll a){
	while(a > 0){
		if(!used[a%10]){
			used[a%10] = true;
			cnt--;
		}
		a /= 10;
	}
}

int main(){
	ll n;
	while(scanf("%lld", &n) == 1){

		fr(i, 10) used[i] = false;

		cnt = 10;

		ll j = 0;
		while(cnt > 0){
			++j;
			solve(n*j);
		}

		printf("%lld\n", j);

	}
}
