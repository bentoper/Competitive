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

string s;

ll v[1123456], o[1123456], f[1123456];

int main(){

	cin >> s;

	ms(f, -1);


	bool last = false;

	for(int i = s.size() - 1; i >= 0; i--){
		if(s[i] == 'o'){ 
			f[i] = i;
			last = false;
			v[i] = v[i + 1];
			o[i] = o[i+1] + v[i];
		}
		else{
			f[i] = f[i+1];
			o[i] = o[i+1];
			if(last == true){
				v[i] = v[i + 1] + 1;
			}
			else{
				v[i] = v[i + 1];
			}
			last = true;
		}
	}

	last = false;

	ll wow = 0;

	fr(i, s.size()){
		
		if(s[i] == 'v'){
			if(f[i] == -1) break;
			if(last == true){
				wow += o[f[i]];
			}
			last = true;
		}
		else{
			last = false;
		}
	}

	cout << wow << endl;

}
