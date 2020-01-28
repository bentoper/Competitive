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

string s[51];
int n;

int type[4];

int main(){
    int Q; cin >> Q;
    while(Q--){
        cin >> n;
        ms(type, 0);
        fr(i, n){
            cin >> s[i];
            int c1 = 0, c0 = 0;
            fr(j, s[i].size()){
                if(s[i][j] == '1') c1++;
                else c0++;
            }
            if(c0%2 && c1%2) type[3]++;
            else if(c0%2) type[0]++;
            else if(c1%2) type[1]++;
            else type[2]++;
        }
        int cnt = 0;
        fr(i, 3) cnt += type[i];
        cnt += type[3] - type[3]%2;
        if(type[0] > 0 || type[1] > 0){
            if(type[3]%2) cnt++;
        } 
        printf("%d\n", cnt); 
    }
}
