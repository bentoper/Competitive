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

int main(){
	stack<ll> s;
	rvr(n);
	fr(i, n){
		ll aux; scanf("%lld", &aux);
		if(s.empty()) s.push(aux);
		else if((s.top()-aux)%2 == 0) s.pop();
		else s.push(aux);
	}
	if(n%2){
		s.pop();
		if(s.empty()){
			printf("YES\n");
			return 0;
		}
		printf("NO\n");
		return 0;
	}
	if(s.empty()){
		printf("YES\n");
		return 0;
	} 
	printf("NO\n");
}