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

int n, a[212345];


int main(){
	int pos;
	scanf("%d", &n);
	fr(i, n){
		scanf("%d", &a[i]);
		if(a[i] == n) pos = i;
	}

	int last = -1;

	fr(i, pos - 1){
		if(last != -1){
			if(last > a[i]){
				printf("No\n");
				return 0;
			}
		}
		last = a[i];
	}

	last = -1;

	for(int i = pos + 1; i < n; i++){
		if(last != -1 && last < a[i]){
			printf("No\n");
			return 0;
		}
		last = i;
	}

	printf("Yes\n");

}








