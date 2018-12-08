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

vi gerente[501]; int idade[501]; int visited[501]; int atual[501];
int N, M, perg, minimo = INF;

void dfs(int start){
    for(auto x: gerente[start]){
        if(!visited[x]){
            visited[x] = 1;
            minimo = min(idade[x], minimo);
            dfs(x);
        }
    }
}

int main(){
    cin >> N >> M >> perg;
    frr(i, N){
        rvr(aux)
        idade[i] = aux;
        atual[i] = i;
    }
    frr(i, M){
        rvr(pai) rvr(filho)
        gerente[filho].pb(pai);
    }
    fr(i, perg){
        char tipo; cin >> tipo;
        if(tipo == EOF) return 0;
        if(tipo == 'P'){
            rvr(aux)
            if(gerente[atual[aux]].empty()){
                char topzera = 42;
                cout << topzera << endl;
            }
            else{
                visited[atual[aux]] = 1;
                dfs(atual[aux]);
                cout << minimo << endl;
                ms(visited, 0); minimo = INF;
            }
        }
        else{
            rvr(aux1) rvr(aux2)
            int placebo = atual[aux1];
            int id = idade[atual[aux1]];
            idade[atual[aux1]] = idade[atual[aux2]];
            idade[atual[aux2]] = id;
            atual[aux1] = atual[aux2];
            atual[aux2] = placebo;
        }
    }
}

