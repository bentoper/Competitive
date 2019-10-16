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

ll n, v[212345];

ll k;

int main(){
	cin >> n >> k;
	fr(i, n){
		cin >> v[i];
	}

	sort(v, v+n);
	
	ll i = 1, pos = n/2;


	while(k != 0){
		if(i == n/2 + 1){
			v[pos] += k/i;
			k = 0;
		}

		else{
			ll diff = v[pos + i] - v[pos];
			if(diff == 0){
				i++;
				continue;
			}
			else{
				if(i*diff <= k){
					v[pos] += diff;
					k -= diff*i;
					i++;
				}
				else{
					v[pos] += k/i;
					k = 0;
				}
			}
		}
	}

	cout << v[pos] << endl;
}
