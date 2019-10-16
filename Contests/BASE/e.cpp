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

int rings, runes;

int r[100][3];

ll pot[30];

void calcpot(){

	ll plc = 1;

	fr(i, 23){
		pot[i] = plc;
		plc *= 2;
	}

}

bool solve(ll mask){

	fr(i, runes){
		int a = r[i][0], b = r[i][1], c = r[i][2];

		if(a > 0 && mask&(1<<(a-1))) continue;
		else if(a < 0 && !(mask&(1<<(abs(a)-1)))) continue;
		if(b > 0 && mask&(1<<(b-1))) continue;
		else if(b < 0 && !(mask&(1<<(abs(b)-1)))) continue;
		if(c > 0 && mask&(1<<(c-1))) continue;
		else if(c < 0 && !(mask&(1<<(abs(c)-1)))) continue;

		return false;
	}

	return true;
}


int main(){
	calcpot();
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &rings, &runes);
		bool caca1 = false, caca2 = false, caca3 = false;

		fr(i, runes){
			int a, b, c;
			scanf("%d%d%d%d", &r[i][0], &r[i][1], &r[i][2], &a);

			a = r[i][0], b = r[i][1], c = r[i][2];


			if(c == 0 || b == 0 || a == 0){
				caca1 = true;
			}

			if(abs(a) > rings || abs(b) > rings || abs(c) > rings) caca2 = true;

			if(abs(a) == abs(b) || abs(c) == abs(b) || abs(c) == abs(a)) caca3 = true;

		}

		if(caca1){
			printf("INVALID: NULL RING\n");
			continue;
		}
		else if(caca2){
			printf("INVALID: RING MISSING\n");
			continue;
		}
		else if(caca3){
			printf("INVALID: RUNE CONTAINS A REPEATED RING\n");
			continue;
		}

		bool deu = false;

		for(ll i = 0; i < pot[rings]; i++){
			if(solve(i)){
				deu = true;
				break;
			}
		}

		if(deu){
			printf("RUNES SATISFIED!\n");
		}
		else{
			printf("RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n");
		}

	}


}
