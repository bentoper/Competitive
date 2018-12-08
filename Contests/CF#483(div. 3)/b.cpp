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

string words[101]; int fodeu = 0;

int compara(string a, string b){
	return (a.size() < b.size());
}

int substring(string a, string b){
	int fodeus = 0;
	fr(i, b.size()){
		if(b[i] == a[0] && i + a.size() <= b.size()){
			fr(j, a.size()){
				if(b[i + j] != a[j]) break;
				if(j == (a.size() - 1)) fodeus = 1;
			}
		}
	}
	return fodeus;
}

int main(){
	rvr(n);
	getline(cin, words[0]);
	fr(i, n){
		getline(cin, words[i]);
	}
	sort(words, words + n, compara);
	fr(i, n - 1){
		if(!substring(words[i], words[i+1])) fodeu = 1;
	}
	if(fodeu){
		printf("NO\n"); return 0;
	}
	printf("YES\n");
	fr(i, n) cout << words[i] << endl;
}
