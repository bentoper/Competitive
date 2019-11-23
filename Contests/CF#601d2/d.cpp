#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) cout << x[i] << " \n"[i==n-1];

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
const int N = 111;


string a[N];

int t, r, c, k, FIRST, REST, rice;

char f[62];

int lim[62];

void solve(int i, int g, int dir){
    if(i == r) return;
    if(dir){
        int j = 0;
        while(lim[g] >= 0 && j < c){
            if(lim[g] == 0 && g != k-1){
                g++;
            }
            if(a[i][j] == 'R'){
                lim[g]--;
            }
            cout << f[g];
            j++;
        }
        cout << endl;
        solve(i+1, g, !dir);

    }
    else{
        int j = c - 1;
        char tmpr[c];
        while(lim[g] >= 0 && j >= 0){
            if(lim[g] == 0 && g != k-1){
                g++;
            }
            if(a[i][j] == 'R'){
                lim[g]--;
            }
            tmpr[j] = f[g];
            j--;
        }
        fr(i, c){
            cout << tmpr[i];
        }
        cout << endl;
        solve(i+1, g, !dir);
    }
}

int bowl(){
    int ret = 0;
    fr(i, r){
        fr(j, c) ret += (a[i][j]=='R');   
    }
    return ret;
}

void init(){
    fr(i, k){
        if(i < FIRST){
            lim[i] = 1 + REST;
        }
        else lim[i] = REST;
    }
}

int main(){
    fastio;
    int t; cin >> t;
    fr(i, 26){
        f[i] = 'a' + i;
    }
    fr(i, 26){
        f[i + 26] = 'A' + i;
    }
    for(int i = 52; i < 62; i++){
        f[i] = '0' + i - 52;
    }
    while(t--){
        cin >> r >> c >> k; 
        getline(cin, a[0]);
        fr(i, r){
            getline(cin, a[i]);
        }
        rice = bowl();
        FIRST = rice%k;
        REST = rice/k;
        init();
        solve(0, 0, 0);
    }
}
