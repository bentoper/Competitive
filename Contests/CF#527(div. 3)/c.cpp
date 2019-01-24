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

int n, peguei = 0, sufixes, prefixes, sizes[200];
string ps[200], s1, s2, palavra;
vector<char> tryone, trytwo;

int mysort(string a, string b){
	if(a.size() < b.size()) return 1;
	if(b.size() > a.size()) return 0;
	return 1;
}

int main(){
	scanf("%d", &n);
	string thrash;
	getline(cin, thrash);
	fr(i, 2*n-2){
		getline(cin, ps[i]);
		if(ps[i].size() == n-1 && !peguei){
			s1 = ps[i]; peguei = 1;
		}
		else if(ps[i].size() == n-1) s2 = ps[i];
	}
	if(n == 2){
		printf("SP\n");
		return 0;
	}
	//dbg(s1); dbg(s2);
	int i = 0;
	for(i = 0; i < n-2 && s1[i+1] == s2[i]; i++);
	if(i == n-2){
		palavra = s1 + s2[n-2];
	}
	else palavra = s1[0] + s2;
	//dbg(i);
	//dbg(palavra);
	fr(i, 2*n-2){
		int j;
		for(j = 0; j < ps[i].size() && ps[i][j] == palavra[j]; j++);
		if(j == ps[i].size()){
			int k;
			for(k = n - ps[i].size(); k < n && palavra[k] == ps[i][k - n + ps[i].size()]; k++);
			if(k == n){
				if(sizes[ps[i].size()]){
					prefixes++;
					tryone.pb('P');
				}
				else{
					sufixes++;
					tryone.pb('S');
					sizes[ps[i].size()] = 1;
				}
			}
			else{
				prefixes++;
				tryone.pb('P');
			}
		}
		else{
			sufixes++;
			tryone.pb('S');
		}
	}
	if(sufixes == prefixes){
		fr(i, 2*n-2){
			cout << tryone[i];
		}
		gnl;
	}
	else{
		palavra = s2 + s1[n-2];
		fr(i, 2*n-2){
			sizes[i] = 0;
		}
		//dbg(palavra);
		fr(i, 2*n-2){
			int j;
			for(j = 0; j < ps[i].size() && ps[i][j] == palavra[j]; j++);
			if(j == ps[i].size()){
				int k;
				for(k = n - ps[i].size(); k < n && palavra[k] == ps[i][k - n + ps[i].size()]; k++);
				if(k == n){
					if(sizes[ps[i].size()]){
					 	prefixes++;
					 	cout << "P";
					}
					else{
						sufixes++;
						cout << "S";
						sizes[ps[i].size()] = 1;
					}
				}
				else{
					prefixes++;
					cout << "P";
				}
			}
			else{
				sufixes++;
				cout << "S";
			}
		}
		gnl;
	}
}
