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


string s;

int main(){
	getline(cin, s);
	int tam = s.size()/2;
	if(s.size() <= 2){
		cout << s;
		return 0;
	}
	if(s.size()%2 == 0) tam--;
	int i = tam + 1;
	int j = tam - 1;
	cout << s[tam];
	while(j >= 0 || i < s.size()){
		if(i < s.size()){
			cout << s[i];
			i++;
		}
		if(j >= 0){
			cout << s[j];
			j--;
		}
	}
	gnl;
}
