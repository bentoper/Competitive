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

stack<int> topsort, outras;
vector<int> adj[26];
int visited[26], processing[26], fodeu;

void dfs(int s){
	if(visited[s]) return;
	visited[s] = 1;
	processing[s] = 1;
	for(int x: adj[s]){
		if(processing[x]) fodeu = 1;
		if(visited[x]) continue;
		dfs(x);
	}
	processing[s] = 0;
	topsort.push(s);
}


int main(){
	string s; rvr(n); string aux;
	getline(cin, s);
	fr(i, n){
		getline(cin, s);
		if(i){
			fr(j, min(s.size(), aux.size())){
				if(s[j] != aux[j]){
					adj[(int) (aux[j] - 'a')].pb((int) (s[j] - 'a'));
					break;
				}
				if(j == min(s.size(), aux.size()) - 1){
					if(aux.size() > s.size()) fodeu = 1;
				}
			}
		}
		aux = s;
	}
	fr(i, 26){
		dfs(i);
	}
	if(fodeu){
		printf("Impossible\n");
		return 0;
	}
	while(!topsort.empty()){
		cout << (char) (topsort.top() + 'a');
		topsort.pop();
	}
	gnl;
}
