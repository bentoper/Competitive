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

ll e[] = {1, 2, 2, 2, 3, 5, 10};
ll g[] = {1, 2, 3, 3, 4, 10};

int clk = 0;

int main(){
	int t; scanf("%d", &t);
	while(t--){

		ll gsum = 0, esum = 0;
		fr(i, 6){
			ll a; scanf("%lld", &a);
			gsum += a*g[i];
		}
		fr(i, 7){
			ll a; scanf("%lld", &a);
			esum += a*e[i];
		}

		printf("Battle %d: ", ++clk);

		if(esum > gsum){
			printf("Evil eradicates all trace of Good\n");
		}
		else if(esum == gsum){
			printf("No victor on this battle field\n");
		}
		else printf("Good triumphs over Evil\n");


	}
}
