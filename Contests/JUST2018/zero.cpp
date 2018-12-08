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

int vetor[100001];

int main(){
	rvr(t);
	while(t--){
		rvr(n); rvr(q);
		int diff = 0;
		map<int, int> mapa;
		frr(i, n){
			rvr(aux);
			vetor[i] = aux;
			if(mapa[aux] == 0 && aux != 0) diff++;
			mapa[aux]++;
		}
		fr(i, q){
			rvr(tipo);
			if(tipo == 1){
				rvr(p); rvr(v);
				mapa[vetor[p]]--;
				if(vetor[p] != 0 && mapa[vetor[p]] == 0) diff--;
				vetor[p] = v;
				if(mapa[v] == 0 && v != 0) diff++;
				mapa[v]++;
			}
			else{
				printf("%d\n", diff);
			}
		}
	}
}
