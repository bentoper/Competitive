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

map<int, int> m;

int dist = 0;

int v[2222];

int ans = INF;

int n;

void solve(int i){

	int cp = dist - 1;
	vi usd;
	usd.pb(v[i]);
	m[v[i]]--;

	int lastposused = i;

	for(int j = i + 1; j < n; j++){
		if(m[v[j]] > 1){
			m[v[j]]--;
			usd.pb(v[j]);
			cp--;
			lastposused = j;
		}
	}

	if(cp == 0){
		ans = min(lastposused - i + 1, ans);
	}

	for(auto x: usd) m[x]++;
}





int main(){
	cin >> n;
	fr(i, n){
		cin >> v[i];
		if(++m[v[i]] > 1){
			dist++;
		}
	}

	if(dist == 0){
		cout << 0 << endl;
		return 0;
	}

	fr(j, n){
		if(m[v[j]] > 1){
			solve(j);
		} 
	}

	cout << ans << endl;
}