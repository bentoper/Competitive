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

int main(){
    int t; cin >> t;
    while(t--){
        string board[9];
        fr(i, 9) cin >> board[i];
        if(board[0][0] != '1') board[0][0] = '1';
        else board[0][0] = '2';
        if(board[1][4] != '1') board[1][4] = '1';
        else board[1][4] = '2';
        if(board[2][8] != '1') board[2][8] = '1';
        else board[2][8] = '2';
        if(board[3][6] != '1') board[3][6] = '1';
        else board[3][6] = '2';
        if(board[4][1] != '1') board[4][1] = '1';
        else board[4][1] = '2';
        if(board[5][5] != '1') board[5][5] = '1';
        else board[5][5] = '2';
        if(board[6][3] != '1') board[6][3] = '1';
        else board[6][3] = '2';
        if(board[7][7] != '1') board[7][7] = '1';
        else board[7][7] = '2';
        if(board[8][2] != '1') board[8][2] = '1';
        else board[8][2] = '2';
        fr(i, 9) cout << board[i] << endl;
    }
}
