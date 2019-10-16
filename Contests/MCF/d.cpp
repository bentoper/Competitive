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


int n;

ll v[212345];

int ans[212345];

//set<ll, int> s;  

vector<pair<ll, int>> pos;

bool mysort(pair<ll, int> a, pair<ll, int> b){
	if(a.first < b.first) return 1;
	if(a.first == b.first && a.second < b.second) return 1;
	return 0;
}

int removedor(int idx, ll sum){

	pair<ll, int> plc = mp(sum, INF);

	int p = lower_bound(all(pos), plc) - pos.begin();

	p--;

	if(p < 0) return 0;

	if(pos[p].first == sum && pos[p].second > idx){
		pos.erase(p+pos.begin());
		
		return removedor(idx, sum)
	}


}

void solve(int num, ll sum){

	int sz = pos.size();

	pair<ll, int> plc = mp(sum, INF);

	int p = lower_bound(all(pos), plc) - pos.begin();

	p--;

	if(pos[p].first == sum){
		ans[pos[p].second] = num;
		plc = mp(sum+n, pos[p].second);
		pos.erase(p + pos.begin());
		int removidos = removedor(plc.second, sum+n);
		solve(num + 1, sum + n);
	}
	else{
		plc = mp(pos[0].first, INF);
		p = lower_bound(all(pos), plc) - pos.begin();

	}
}

int main(){
	cin >> n;
	fr(i, n){
		ll a; cin >> a;
		v[i] = a;

		pos.pb({a, i});
		//s.insert({a, i});
	}

	sort(all(pos), mysort);

	solve(1, 0);

	fr(i, n){
		cout << ans[i] << " ";
	}

	cout << endl;

}
