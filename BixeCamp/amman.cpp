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

int students[100001], locations[100001], fre, n, m, q;

int main(){
	scanf("%d%d%d", &n, &m, &q);
	fre = m;
	frr(i, n){
		scanf("%d", &students[i]);
		if(locations[students[i]] == 0) fre--;
		locations[students[i]]++;
	}
	fr(i, q){
		rvr(aux1) rvr(aux2)
		locations[students[aux1]]--;
		if(locations[students[aux1]] == 0) fre++;
		students[aux1] = aux2;
		if(locations[aux2] == 0) fre--;
		locations[aux2]++;
		printf("%d\n", fre);
	}
}
