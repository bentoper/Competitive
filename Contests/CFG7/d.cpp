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

set<string> S, S1;

bool pal(string a){
    int nn = a.size();
    fr(i, nn/2){
        if(a[i] != a[nn - 1 - i]) return false;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size(), plc = n, st = 0;
        fr(i, n/2){
            if(s[i] == s[n - 1 - i]) plc -= 2, st++;
            else break;
        }
        if(plc <= 0){
            cout << s << endl;
            continue;
        }
        string vaca, mst;
        int ans = 0;
        for(int j = st, i = 0; i < plc; i++){
            vaca.push_back(s[j + i]);
            if(pal(vaca)){
                ans = i + 1;
                mst = vaca;
            }
        }
        vaca.clear();
        for(int j = n - 1 - st, i = 0; i < plc; i++){
            vaca.push_back(s[j - i]);
            if(pal(vaca)){
                if(i + 1 > ans){
                    ans = i+1;
                    mst = vaca;
                }
            }
        }
        fr(i, st){
            cout << s[i];
        }
        cout << mst;
        fr(i, st){
            cout << s[st - i - 1];
        }
        cout << endl;
    }
}
