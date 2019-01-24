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

ll memo[100000][2];
ll w[100000];
string s[100000][2];

int n;

string reversed(string a, int r){
	if(r == 1){
		string s = "";
		int sz = a.size();
		fr(i, sz) s.append(a.end() - 1 - i, a.end() - i);
		return s; 
	}
	return a;
}

ll dp(int i, int cat){
	if(i == n - 1){
		if(s[i-1][cat] <= s[i][0]){
			memo[i][cat] = 0;
		}
		else if(s[i-1][cat] <= s[i][1]){
			memo[i][cat] = w[i];
		}
		else memo[i][cat] = llINF;
	}
	if(memo[i][cat] == -1){
		if(i > 0){
			if(s[i-1][cat] <= s[i][0]){
				if(s[i-1][cat] <= s[i][1]){
					ll o = dp(i+1, 1);
					if(o != llINF) o += w[i];
					memo[i][cat] = min(dp(i+1, 0), o);
				}
				else memo[i][cat] = dp(i+1, 0);
			}
			else{
				if(s[i-1][cat] <= s[i][1]){
					ll o = dp(i+1, 1);
					if(o != llINF) o += w[i];
					memo[i][cat] = (o);
				}
				else{
					memo[i][cat] = llINF;
				}
			}
		}
		else{
			ll o = dp(i+1, 1);
			if(o != llINF) o += w[i];
			memo[i][cat] = min(dp(i+1, 0), o);
		}
	}
	return memo[i][cat];
}



int main(){
	cin >> n;
	fr(i, n) cin >> w[i];
	getline(cin, s[0][0]);
	fr(i, n){
		getline(cin, s[i][0]);
		s[i][1] = reversed(s[i][0], 1);
	}
	/*fr(i, n){
		cout << s[i][0] << " " << s[i][1] << endl;
	}*/
	ms(memo, -1);
	dp(0, 0);
	ll out = memo[0][0];
	if(out == llINF) cout << -1;
	else cout << out;
	gnl;
}
