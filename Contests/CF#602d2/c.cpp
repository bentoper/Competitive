#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], i==n-1);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define ss(x) scanf("%d", &x)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string base = "()";

int main(){
    fastio;
    int t, n, k; cin >> t;
    
    while(t--){
        cin >> n >> k;
        string s, plc;
        cin >> s;
        fr(i, k-1){
            plc += base;
        }
        int l = n - 2*k  + 2;
        fr(i, l/2){
            plc += '(';
        }
        fr(i, l/2) plc += ')';
        vector<pii> op;
        fr(i, n){
            if(s[i] == plc[i]) continue;
            else{
                int j = 1;
                while(s[i + j] != plc[i]) j++;
                fr(k, j+1/2){
                    swap(s[i + k], s[i + j - k]);
                }
                op.pb(mp(i, i+j));
            }
        }
        cout << op.size() << endl;
        fr(i, op.size()){
            cout << op[i].first + 1 << " " << op[i].second + 1 << endl;
        }
        //cout << s << endl;
    }
}
