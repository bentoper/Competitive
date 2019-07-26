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


int t, n;
int s[112345];




int main(){
	scanf("%d", &t);
	while(t--){
		int MAX_1 = -1, MAX_2 = -1;

		scanf("%d", &n);

		

		ms(s, 0);

		s[0] = n;

		fr(i, n){
			int a;
			scanf("%d", &a);
			if(a > MAX_1) MAX_1 = a;
			else if(a > MAX_1) MAX_2 = a;
			s[a + 1]--;
		}
		
		frr(i, MAX_1){
			s[i] += s[i - 1];
			//printf("s[%d] = %d\n", i, s[i]);
		}

		int lk = 0, top = n, base = 0, mid = (top + base)/2;

		while(top >= base){
			//printf("mid = %d lk = %d\n", mid, lk);
			if(s[1] - 2 >= mid && s[mid+1] >= 2){
				lk = mid;
				base = mid + 1; 	
			}
			else{
				top = mid - 1;
			}
			mid = (base+top)/2;
		}

		printf("%d\n", lk);

	}

}












