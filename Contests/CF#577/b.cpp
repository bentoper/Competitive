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

int n, a[112345];

ll sum, xoxo;

int main(){
	int n; cin >> n;
	
	fr(i, n){
		cin >> a[i];
	}

	sort(a, a+n);

	ll curr = 0;
	int i = n-1;

	while(i >= 0){
		if(curr == 0){
			curr = a[i];
			if(i > 0) curr -= a[i-1];
			i -= 2;
		}
		else{
			if(curr >= a[i]){
				curr -= a[i];
			}
			else{
				curr = a[i] - curr;
			}
			i--;
		}
	}

	if(curr != 0){
		curr = 0;
		i = 0;
		while(i <= n-1){
		if(curr == 0){
			curr = a[i];
			if(i < n - 1) curr = a[i+1] - curr;
			i += 2;
		}
		else{
			curr = a[i + ]
		}
	}

		cout << "NO\n";
		return 0;
	}

	else cout << "YES\n";

}
