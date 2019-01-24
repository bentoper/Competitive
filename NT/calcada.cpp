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

int n, a, b, x, y;

int gcd(int a, int b){
	return a%b==0?b:gcd(b, a%b);
}

int main(){
	scanf("%d",&n);
	fr(i, n){
		scanf("%d%d%d%d", &a, &b, &x, &y);
		if(x - a == 0) printf("%d", abs(b-y)+1);
		else if(y - b == 0) printf("%d", abs(x-a)+1);
		else{
			int d = gcd(abs(x-a), abs(y-b));
			if(x - a < 0 && y - b < 0){
				int aux1 = a, aux2 = b;
				a = x;
				b = y;
				x = aux1;
				b = aux2;
				int dy = (x - a)/d;
				int resp;
				if(x - a != d) resp = (y - b)/dy;
			}
		}
	}
}
