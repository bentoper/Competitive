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
    int q; cin >> q;
    while(q--){
        ll c[3];
        fr(i, 3) cin >> c[i];
        sort(c, c+3);
        if(c[1] == c[2] && c[2] == c[0]){
            cout << 0 << endl;
            continue;
        }
        if(c[0] == c[1] && c[1] < c[2]){
            c[0]++;
            c[1]++;
            if(c[0] < c[2]) c[2]--;
        }
        else if(c[1] == c[2] && c[0] < c[1]){
            c[0]++;
            if(c[0] < c[1]){
                c[1]--;
                c[2]--;
            }
        }
        else{
            c[0]++;
            c[2]--;
        }   
        cout << abs(c[0] - c[1]) + abs(c[1] - c[2]) + abs(c[0] - c[2]) << endl;
        
    }
}
