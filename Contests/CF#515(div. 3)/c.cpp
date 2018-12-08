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

int esq = 0; int dir = 0;
map<int, int> fila;

int main(){
	fastio;
	int q; cin >> q; int first = 0;
	while(q--){
		char t; cin >> t;
		if(t == 'L'){
			int aux; cin >> aux;
			fila[aux] = esq;
			esq--;
			if(first == 0){
				first = 1; dir = 1;
			}
		}
		else if(t == 'R'){
			int aux; cin >> aux;
			fila[aux] = dir;
			dir++;
			if(first == 0){
				first = 1; esq = -1;
			}
		}
		else{
			int proc; cin >> proc;
			int aux = fila[proc];
			if(aux == 0) cout << min(dir - 1, -esq - 1);
			else if (aux < 0) cout << min(dir - 1 - aux, aux -esq - 1);
			else cout << min(dir - 1 - aux, aux - esq - 1);
			gnl;		
		}
	}
}