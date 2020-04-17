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
#define MAX 100001

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


// pai inicializa com p[i] = i e peso = 0, qtd = 1;
int pai[MAX], peso[MAX], qtd[MAX];

int N, M, cnt;


int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	int px = find(x);
	int py = find(y);

	if(px == py) return;

	if(peso[px] > peso[py]){
		pai[py] = px;
		qtd[px] += qtd[py];
	}
	else{
		pai[px] = py;
		if(peso[px] == peso[py]) peso[py]++;
		qtd[py] += qtd[px];
	}

}


int main(){
	scanf("%d%d", &N, &M);
	while(N != 0 && M != 0){
		cnt = 0;
		frr(i, N){
			scanf("%d", &qtd[i]);
			pai[i] = i;
			peso[i] = 0;
		}
		fr(i, M){
			rvr(q); rvr(a); rvr(b);
			if(q == 1) join(a, b);
			else{
				int pater = find(1);
				a = find(a);
				b = find(b);
				if(pater == a){
					if(qtd[a] > qtd[b]) cnt++;
				}
				if(pater == b){
					if(qtd[b] > qtd[a]) cnt++;
				}   
			}
		}
		printf("%d\n", cnt);
		scanf("%d%d", &N, &M);
	}

}
