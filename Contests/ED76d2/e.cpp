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
const int N = 212345;

int p[N];
int memo[N][4];
int n;

int dp(){
    for(int c = 1; c <= n; c++){
        fr(i, 3){
            memo[c][i] = INF;
            if(i) memo[c][i] = min(memo[c][i - 1], memo[c][i]);
            memo[c][i] = min(memo[c][i], (memo[c-1][i] + (p[c] != i)));
        }
    }
    return memo[n][2];
}

int main(){
    int k[3];
    
    fr(i, 3) {scanf("%d", &k[i]); n += k[i];}
    fr(i, 3){
        fr(j, k[i]){
            rvr(a);
            p[a] = i;
        }
    }
    printf("%d\n", dp());
}
