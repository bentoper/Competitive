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


vi op;

int main(){
    int n; cin >> n;
    string s, sl;
    cin >> s;
    fr(i, n) sl += s[i];
    char st = s[0];
    char b = 'B', w = 'W';
    for(int i = 1; i < n - 1; i++){
        if(s[i] != st){
            s[i] = st;
            if(s[i+1] == b) s[i+1] = w;
            else s[i+1] = b;
            op.pb(i+1);
        }
    }
    bool deu = true;
    fr(i, n){
        if(s[i] != st) deu = false;
    }
    if(deu){
        cout << op.size() << endl;
        fr(i, op.size()){
            cout << op[i] << " \n"[i==op.size()-1];
        }
        return 0;
    }
    if(sl[0] == b){
        sl[0] = w;
        if(sl[1]==b) sl[1] = w;
        else sl[1] = b;
    }
    else{
        sl[0] = b;
        if(sl[1]==b) sl[1] = w;
        else sl[1] = b;
    }
    op.clear();
    st = sl[0];
    op.pb(1);
    for(int i = 1; i < n - 1; i++){
        if(sl[i] != st){
            sl[i] = st;
            if(sl[i+1] == b) sl[i+1] = w;
            else sl[i+1] = b;
            op.pb(i+1);
        }
    }
    deu = true;
    fr(i, n){
        if(sl[i] != st) deu = false;
    }
    if(deu){
        cout << op.size() << endl;
        fr(i, op.size()){
            cout << op[i] << " \n"[i==op.size()-1];
        }
        return 0;
    }
    cout << -1 << endl;
}
