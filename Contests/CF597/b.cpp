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

char ans[200];

int main(){
    int t; cin >> t;
    while(t--){
        int cnt = 0;
        int n, a, b, c; cin >> n >> a >> b >> c;
        string s; cin >> s;
        fr(i, n){
            if(s[i] == 'R'){
                if(b){
                    ans[i] = 'P';
                    b--;
                    cnt++;
                }
                else ans[i] = 'C';                
            }
            else if(s[i] == 'P'){
                if(c){
                    ans[i] = 'S';
                    cnt++;
                    c--;
                }
                else ans[i] = 'C';
            }
            else{
                if(a){
                    a--;
                    ans[i] = 'R'; 
                    cnt++;
                }
                else ans[i] = 'C';
            }
        }
        if(cnt < (n+1)/2){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            fr(i, n){
                if(ans[i] != 'C') cout << ans[i];
                else{
                    if(b){
                        b--;
                        cout << "P";
                    }
                    else if(a){
                        a--;
                        cout << "R";
                    }
                    else{
                        c--;
                        cout << "S";
                    }
                }
            }
            cout << endl;
        }
    }
}
