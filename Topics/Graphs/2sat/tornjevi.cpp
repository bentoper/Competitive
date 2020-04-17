//https://www.spoj.com/problems/TORNJEVI/
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

#define MAXN 11234567 //twice amount of stuff

ll clk = 0, qnt = 0, counter = 0;

int low[MAXN], pre[MAXN], id[MAXN], numSCC = 0;

bool eval[MAXN];

vector<int> adj[MAXN];

stack<int> nodes;

void dfs(int v){

	nodes.push(v);

	pre[v] = clk++;
	low[v] = pre[v];

	for(auto x: adj[v]){
		if(pre[x] == -1){
			dfs(x);
		}
		low[v] = min(low[v], low[x]);
	}

	if(low[v] == pre[v]){
		while(true){
			int j = nodes.top();
			nodes.pop();
			id[j] = numSCC;
			low[j] = MAXN;
			if(j == v) break;
		}
		numSCC++;
	}

}

int neg(int i){
	if(i < qnt/2) return i + qnt/2;
	return i - qnt/2; 
}


void add_imp(int i, int j){
	adj[i].pb(j);
}

void add_or(int i, int j){
	add_imp(neg(i), j);
	add_imp(neg(j), i);
}

void add_xor(int i, int j){
	add_or(i, j);
	add_or(neg(i), neg(j));
}

void force_var(int i){
	add_or(i, i);
}

bool sat(){
	for(int i = 0; i < qnt; i++){
		if(pre[i] == -1) dfs(i);
	}
	for(int i = 0; i < qnt/2; i++){
		if(id[i] == id[neg(i)]) {return false;}
		eval[i] = id[neg(i)] > id[i];
		eval[neg(i)] = !eval[i];
	}

	return true;
}

int up(int i){
	return 2*i;
}

int right(int i){
	return 2*i + 1;
}

int left(int i) {return neg(right(i));}
int down(int i) {return neg(up(i));}

char board[112][112];
int r, s, ide[112][112];

int tower_up[112][112], tower_down[112][112], tower_left[112][112], tower_right[112][112];

int main(){
	cin >> r >> s;
	fr(i, r){
		fr(j, s) tower_left[i][j] = tower_right[i][j] = tower_up[i][j] = tower_down[i][j] = -1;
	}

	fr(i, r){
		fr(j, s){
			char c; cin >> c; 
			board[i][j] = c;
			if(c == 'T') {
				ide[i][j] = counter++;
			}
			if(c == '#'){
				tower_left[i][j] = -1;
				tower_up[i][j] = -1;
			}
			else{
				if(i > 0 && board[i-1][j] == 'T') tower_up[i][j] = ide[i-1][j];
				else if(i > 0) tower_up[i][j] = tower_up[i-1][j];
				if(j > 0 && board[i][j - 1] == 'T') tower_left[i][j] = ide[i][j-1];
				else if(j > 0) tower_left[i][j] = tower_left[i][j-1];
			}
		}
	}

	qnt = counter*4;

	fr(i, qnt){
		pre[i] = -1;
	}

	for(int i = r-1; i >= 0; i--){
		for(int j = s - 1; j >= 0; j--){
			char c = board[i][j];
			if(c == '#'){
				tower_right[i][j] = -1;
				tower_down[i][j] = -1;
			}
			else{
				if(j < s - 1 && board[i][j+1] == 'T') tower_right[i][j] = ide[i][j+1];
				else if(j < s - 1) tower_right[i][j] = tower_right[i][j + 1];
				if(i < r-1 && board[i+1][j] == 'T') tower_down[i][j] = ide[i+1][j];
				else if(i < r - 1) tower_down[i][j] = tower_down[i+1][j];				
			}	
		}
	}

	fr(i, r){
		fr(j, s){
			if(board[i][j] == 'n'){
				if(tower_down[i][j] != -1 && tower_up[i][j] != -1){
					if(tower_right[i][j] != -1){
						force_var(left(tower_right[i][j]));
					}
					else force_var(right(tower_left[i][j]));
				}
				else if(tower_right[i][j] != -1 && tower_left[i][j] != -1){
					if(tower_down[i][j] != -1){
						force_var(up(tower_down[i][j]));
					}
					else force_var(down(tower_up[i][j]));
				}
				else{
					int a = -1, b = -1;
					if(tower_down[i][j] != -1) a = up(tower_down[i][j]);
					if(tower_up[i][j] != -1) a = down(tower_up[i][j]);
					if(tower_right[i][j] != -1) b = left(tower_right[i][j]);   
					if(tower_left[i][j] != -1) b = right(tower_left[i][j]);
					if(a == -1) force_var(b);
					else if(b == -1) force_var(a);
					else add_or(a, b);
				}

			}
			if(board[i][j] == 'T'){
				int plc = ide[i][j];
				if(tower_up[i][j] != -1){
					force_var(down(plc));
				}
				if(tower_down[i][j] != -1){
					force_var(up(plc));
					//cout << "down "; dbg(i); dbg(j);
				}
				if(tower_left[i][j] != -1){
					//cout << "left "; dbg(i); dbg(j);
					force_var(right(plc));
				}
				if(tower_right[i][j] != -1){
					//cout << "right "; dbg(i); dbg(j);
					force_var(left(plc));
				}
			}
		}
	}



	if(sat()){
		/*fr(i, qnt){
			cout << i << ": ";
			for(int x: adj[i]){
				cout << x << " ";
			}
			cout << endl;
		}*/
		fr(i, r){
			fr(j, s){
				if(board[i][j] == 'T'){
					int plc = ide[i][j];
					if(eval[left(plc)] && eval[down(plc)]) cout << '1';
					if(eval[down(plc)] && eval[right(plc)]) cout << '2';
					if(eval[right(plc)] && eval[up(plc)]) cout << '3';
					if(eval[up(plc)] && eval[left(plc)]) cout << '4';
				}
				else cout << board[i][j];
			}
			cout << endl;
		}
	}
}
