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

int n, m;

int teams[101][3], nums[101];

int sorteia(int a, int b){
	if(teams[a][0] > teams[b][0]) return 1;
	if(teams[a][0] < teams[b][0]) return 0;
	if(teams[a][1] > teams[b][1]) return 1;
	if(teams[a][1] < teams[b][1]) return 0;
	if(teams[a][2] > teams[b][2]) return 1;
	if(teams[a][2] < teams[b][2]) return 0;
	return a < b;
}

int main(){
	cin >> n >> m;
	fr(i, m){
		int o, p, b; cin >> o >> p >> b;
		teams[o - 1][0]++; 
		teams[p - 1][1]++; 
		teams[b - 1][2]++; 
	}
	fr(i, n){
		nums[i] = i;
	}
	sort(nums, nums+n, sorteia);
	fr(i, n){
		printf("%d ", nums[i] + 1);
	}
	gnl;
}
