#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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

int n, seq[111], sz, memo[111][111][111][2];
vi fr;


int dp(int i, int e, int o, int l){
    if(e < 0 || o < 0) return INF;
    if(i == n-1) return 0;
    if(memo[i][e][o][l] != -1) return memo[i][e][o][l];
    if(seq[i] != 0){
        int md = seq[i]%2;
        if(seq[i+1] == 0) memo[i][e][o][l] = min(md + dp(i+1, e - 1, o, 0), 1 - md + dp(i+1, e, o-1, 1));
        else memo[i][e][o][l] = dp(i+1, e, o, md) + abs(md - seq[i+1]%2);
        return memo[i][e][o][l];
    }
    if(l == -1){
        if(seq[i+1] == 0) memo[i][e][o][l] = min(dp(i+1, e - 2, o, 0), min(1 + dp(i+1, e-1, o-1, 1), min(1 + dp(i+1, e-1, o-1, 0), dp(i+1, e, o - 2, 1))));
        else memo[i][e][o][l] = min(abs(seq[i+1]%2) + dp(i+1, e-1, o, 0), abs(1 - seq[i+1]%2) + dp(i+1, e, o-1, 1));
        return memo[i][e][o][l];    
    }
    if(seq[i+1] == 0) memo[i][e][o][l] = min(l + dp(i+1, e - 1, o, 0), 1 - l + dp(i+1, e, o - 1, 1));
    else memo[i][e][o][l] = abs(l - seq[i+1]%2) + dp(i+1, e, o, l);
    return memo[i][e][o][l];
}

int main(){
    ms(memo, -1);
    scanf("%d", &n);
    int ev = n/2; 
    int od = n - ev;
    fr(i, n){
        scanf("%d", &seq[i]);
        if(seq[i] == 0) fr.pb(i);
        else{
            if(seq[i]%2) od--;
            else ev--;
        }
    }
    sz = fr.size();
    if(sz == 0){
        int sss = 0;
        fr(i, n-1){
            if(seq[i]%2 != seq[i+1]%2) sss++;
        }
        printf("%d\n", sss);
        return 0;
    }
    printf("%d\n", dp(0, ev, od, -1));
}
