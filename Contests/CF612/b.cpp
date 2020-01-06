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

map<string, int> m;

string a[1600];

ll ans = 0;

bool used[1600][1600];

int main(){
    int n, k; cin >> n >> k;
    frr(i, n){
        cin >> a[i];
        m[a[i]] = i;
    }
    frr(i, n){
        for(int j = i + 1; j <= n; j++){
            if(used[i][j]) continue;
            string plc;
            fr(l, k){
                if(a[i][l] == a[j][l]) plc.push_back(a[i][l]);
                else if((a[i][l] == 'S' || a[j][l] == 'S') && (a[i][l] == 'E' || a[j][l] == 'E')) plc.push_back('T');
                else if((a[i][l] == 'T' || a[j][l] == 'T') && (a[i][l] == 'E' || a[j][l] == 'E')) plc.push_back('S');
                else if((a[i][l] == 'T' || a[j][l] == 'T') && (a[i][l] == 'S' || a[j][l] == 'S')) plc.push_back('E');
            }
            if(m[plc] != 0){
                int pos = m[plc];
                used[i][pos] = true;
                used[j][pos] = true;
                used[pos][j] = true;
                used[pos][i] = true;
                used[i][j] = true;
                used[j][i] = true;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
