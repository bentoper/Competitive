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


int tsum, bsum, dodd, mix, n;

int main(){
	scanf("%d", &n);
	fr(i, n){
		int a, b; scanf("%d%d", &a, &b);
		a %= 2;
		b %= 2;
		tsum += a;
		bsum += b;
		if(a == 1 && b == 1) dodd++;
		if((a == 1 && b == 0) || (a == 0 && b == 1)) mix++;
	}

	if(dodd%2 == 1 && mix == 0){
		printf("-1\n"); return 0;
	}

	tsum %=2; bsum%=2;
	dodd %= 2; mix %= 2;
	if(tsum == 0 && bsum == 0){
		printf("0\n");
		return 0;
	}

	if(dodd == 1 && mix == 1){
		printf("-1\n"); return 0;
	}

	if(dodd == 1 && mix == 0){
		printf("1\n"); return 0;	
	}

	if(dodd == 0 && mix == 1){
		printf("-1\n"); return 0;	
	}

	if(dodd == 0 && mix == 0){
		printf("1\n"); return 0;	
	}



}






