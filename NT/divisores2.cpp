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

int A, B, C, D, ans = INF;
vi divs;

bool solve(int x){
	if(x%A == 0 && x%B != 0 && D%x != 0) return true;
	return false;
}



int main(){
	scanf("%d%d%d%d", &A, &B, &C, &D);
	for(int i = 1; i*i <= C; i++){
		if(C%i == 0){
			if(solve(i)) ans = min(ans, i);
			if(solve(C/i)) ans = min(ans, C/i);
		}
	}
	if(ans != INF) printf("%d\n", ans);
	else printf("-1\n");
}
