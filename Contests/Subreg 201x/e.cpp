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

#define stp int a; cin >> a;
#define gnl cout << endl
#define olar cout << "olar" << endl
#define otp(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll tot = 0, c = 1;
int mx = -INF, mn = INF, pot2[16], permuts[134000];
int N, memo[134000];
string lista[0x3f];

int remove(int bit_value, string value){
	vector<char> num;
	fr(i, 16){
		if((bit_value/pot2[i])%2){
			if(i < 10) num.pb('0' + i);
			else num.pb('a' + i - 10);
		}
	}
	vector<char> out;
	for(char z: value){
		bool tem = false;
		for(char x: num){
			if(x == z) tem = true;
		}
		if(!tem) out.pb(z);
	}
	int sum = 0, aux = 1, tamanho = out.size();
	for(int i = tamanho - 1; i >= 0; i--){
		if(isalpha(out[i])) sum += (out[i] - 'a' + 10)*aux;
		else sum += (out[i] - '0')*aux;
		aux = aux*16;
	}
	return sum;
}

int sum(int bit_value){
	if(memo[bit_value] == -1){
		memo[bit_value] = 0;
		fr(i, N) memo[bit_value] += remove(bit_value, lista[i]);
	}
	return memo[bit_value];
}

int permutations(int bit_value, int answer){
    if(bit_value == c) return 0;
    if(permutations[bit_value] != -1)
        permutations[bit_value] = 0;
        fr(i, 16){
            if((bit_value/pot2[i])%2) continue;
            permutations[bit_value] += permutations(bit_value + pot2[i], answer + sum(bit_value + pot2[i]));
        }
    return;
}

int main(){
    cin >> N;
    pot2[0] = 1;
    ms(memo, -1);
    fr(i, 15){
        pot2[i+1] = pot2[i]*2;
        c += pot2[i+1];
    }
    string lixo; getline(cin, lixo);
    fr(i, N){
        getline(cin, lista[i]);
    }
    permutations(0, 0);
    otp(mx); otp(mn); otp(tot);
}
