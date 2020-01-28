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


string a[11];

set<string> S;

vector<pair<string, int>> dup;


int main(){
    int t; cin >> t;
    while(t--){
        S.clear(), dup.clear();
        int n; cin >> n;
        fr(i, n){
            cin >> a[i];
            if(S.find(a[i]) != S.end()) dup.pb({a[i], i});
            else S.insert(a[i]); 
        }
        if(dup.size() == 0){
            cout << 0 << "\n";
            fr(i, n) cout << a[i] << " \n";
        }
        else{
            cout << (int)dup.size() << "\n";
            for(auto p: dup){
                string plc = p.first;
                fr(k, 4){
                    char vaca = plc[k];
                    fr(i, 9){
                        plc[k] = i + '0';
                        if(S.find(plc) == S.end()){
                            a[p.second] = plc;
                            S.insert(plc);
                            goto END;
                        }
                    }
                    plc[k] = vaca;
                }
                END:;
            }
            fr(i, n) cout << a[i] << "\n";
        }
    }
}
