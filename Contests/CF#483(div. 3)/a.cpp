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

int nums[101]; int indexes[101]; int diffs = 0;

int main(){
	rvr(n); rvr(k);
	frr(i, n){
		rvr(aux);
		nums[aux]++;
		if(nums[aux] == 1){
			indexes[aux] = i;
			diffs++;
		}
	}
	if(diffs < k){
		printf("NO\n");
		return 0;
	}
	int i = 1;
	printf("YES\n");
	while(k--){
		while(!indexes[i]) i++;
		printf("%d ", indexes[i]);
		i++;
	}
}
