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

int main(){
    int t; cin >> t;
    while(t--){
        string s, c;
        cin >> s >> c;
        if(s < c){
            cout << s << endl;
            continue;
        }
        int sz = s.size();
        bool deu = false;
        fr(i, sz){
            char a = s[i];
            int idx = -1;
            for(int j = i + 1; j < sz; j++){
                if(s[j] <= a && s[j] != s[i]){
                    a = s[j];
                    idx = j;
                }                
            }
            if(idx != -1){
                deu = true;
                swap(s[i], s[idx]);
                break;
            }
        }
        if(deu){
            if(s < c){
                cout << s << endl;
                continue;
            }
        }
        cout << "---\n";

    }
}
