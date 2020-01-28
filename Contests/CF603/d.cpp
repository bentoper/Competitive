#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
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
const int MAX = 27;

// pai inicializa com p[i] = i e peso = 0, qnt = 1;
int pai[MAX], peso[MAX];

bool vis[MAX];

int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(peso[x] > peso[y]) swap(x, y);

	pai[x] = y;
	if(peso[x] == peso[y]) peso[y]++;

}


int main(){
    vector<int> comp;
    frr(i, 26){
        pai[i] = i;
    }
    int sz = 0;
    int n; cin >> n;
    fr(i, n){
        string s; cin >> s;
        for(char c: s){
            if(!vis[c - 'a' + 1]) {
                sz++;
                vis[c-'a'+1] = 1;
            }
            for(char cc: s){
                if(!vis[cc - 'a' + 1]) {
                    sz++;
                    vis[cc-'a'+1] = 1;
                }
                if(c != cc){
                    if(find(cc - 'a' + 1) != find(c - 'a' + 1)){
                        join(c - 'a' + 1, cc - 'a' + 1);
                        sz--;
                    }
                }
            }
        }        
    }
    cout << sz << endl;
}
