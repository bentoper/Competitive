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
#define MAX 1000001

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[MAX], peso[MAX], qnt[MAX];
ll val[MAX];


int find(int x){
	return (pai[x] < 0)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	int px = -find(x);
	int py = -find(y);

	if(px == py) return;

	if(peso[px] > peso[py]){
		pai[py] = -px;
		qnt[px] += qnt[py];
	}
	else{
		pai[px] = -py;
		if(peso[px] == peso[py]) peso[py]++;
		qnt[py] += qnt[px];
	}

}


int main(){
	while(scanf("%d%d", &n, &m)){
		frr(i, n){
			pai[i] = -i;
			val[i] = i;
		}
		frr(i, n) qnt[i] = 1;
		rvr(a); rvr(b); 
		if(a < 3){
			int pb = find(b);
			rvr(c);
			int pc = find(c);
			if(a == 1) join(b, c);
			else{

			}

		}
		else printf("%d %lld", qnt[-find(b)], val[-find(b)])
	}

}
