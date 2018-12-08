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

int main(){
	string s;
	getline(cin, s);
	int c = 1;
	fr(i, s.size()){
		while(i + c < s.size() && s[i] == s[i + c]){
			c++;
		}
		if(c != 1){
			if(c%2 == 0){
				char change = 'a';
				if(s[i] == 'a') change = 'b';
				for(int j = 1; j <= c - 1; j += 2){
					s[i + j] = change;
					while(i + j + 1 < s.size() && (s[i + j] == s[i] || s[i + j] == s[i + j + 1])){
						change++;
						s[i + j] = change;
					}
				}
			}
			else{
				for(int j = 1; j < c; j += 2){
					if(s[i] == 'a') s[i + j] = 'b';
					else s[i + j] = 'a';
				}
			}
			c = 1;
		}
	}
	otp(s);
}
