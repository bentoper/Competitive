#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define rvr(x)  int x; cin >> x;

#define ms(x,i)	memset(x,i,sizeof(x))

#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
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

vi pai[10001]; int gera[10001]; int presentes[10001]; int gerard[10001];
int N, M;
int main(){
    cin >> N >> M;
    frr(i, N){
        int aux; cin >> aux;
        pai[i].pb(aux);
    }
    frr(i, N){
        int ger = 0;
        int base = i;
        while(!(pai[base].empty())){
            base = pai[base][0];
            ger++;
        }
        gera[ger]++;
        gerard[i] = ger;
    }
    fr(i, M){
        rvr(aux);
        presentes[gerard[aux]]++;
    }
    int counter = 1;
    while(gera[counter]){
        double result = (double) presentes[counter]/gera[counter];
        result = result*100;
        cout << setprecision(2) << fixed << result << " ";
        counter++;
    }
    gnl;
}
