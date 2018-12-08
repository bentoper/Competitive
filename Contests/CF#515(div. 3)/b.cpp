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

int casa[1000];

int main(){
	rvr(n); rvr(r);
	int c = 0;
	fr(i, n){
		scanf("%d", &casa[i]);
	}
	int count = 0; int i = 0;
	while(i < n){
		int last = 0, conseguiu = 0;
		for(int j = i; j <= i + r - 1 && j < n; j++){
			if(casa[j]){
				last = j; conseguiu = 1;
			}
		}
		if(conseguiu){
			i = last + r;
			count ++;
		}
		else{
			for(int j = i; j >= i - r + 1 && j >=0; j--){
				if(casa[j]){
					last = j; conseguiu = 1;
					break;
				}	
			}
			if(conseguiu){
				i = last + r;
				count ++;
			}
			else{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", count);
}
