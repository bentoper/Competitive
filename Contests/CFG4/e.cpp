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

string s;
int n;

stack<char> stk;
vector<char> q;

void solve(int start, int end){
	
	if(start > end){
		fr(i, q.size()) cout << q[i];
		while(!stk.empty()){
			cout << stk.top();
			stk.pop();
		}
		cout << endl;
		return;
	}

	if(end == start){
		fr(i, q.size()) cout << q[i];
		cout << s[start];
		while(!stk.empty()){
			cout << stk.top();
			stk.pop();
		}
		cout << endl;
		return;
	}

	if(end - 1 == start){
		fr(i, q.size()) cout << q[i];
		if(s[end] == s[start]) cout << s[end] << s[start];
		else cout << s[end];
		while(!stk.empty()){
			cout << stk.top();
			stk.pop();
		}
		cout << endl;
		return;	
	}

	if(end - 2 == start){
		fr(i, q.size()) cout << q[i];
		if(s[end] == s[start] || s[end] == s[start + 1]) cout << s[end] << s[end];
		else cout << s[end];
		while(!stk.empty()){
			cout << stk.top();
			stk.pop();
		}
		cout << endl;

		return;	
	}



	if(s[start] == s[end] || s[start] == s[end - 1]){
		q.pb(s[start]);
		stk.push(s[start]);	
	}
	else{
		q.pb(s[start + 1]);
		stk.push(s[start + 1]);	
	}

	solve(start + 2, end - 2);
}


int main(){
	cin >> s;
	n = s.size();
	if(n <= 3){
		cout << s[0] << endl;
		return 0;
	} 
	solve(0, n-1);
}
