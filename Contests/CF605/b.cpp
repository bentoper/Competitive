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

map<char, int> M;
int freq[4];

int main(){
    M['U'] = 0;
    M['D'] = 1;
    M['L'] = 2;
    M['R'] = 3;
    int q; cin >> q;
    while(q--){
        ms(freq, 0);
        string s; cin >> s;
        int n = s.size();
        fr(i, n){
            freq[M[s[i]]]++;
        }
        freq[0] = min(freq[0], freq[1]);
        freq[1] = min(freq[0], freq[1]);
        freq[2] = min(freq[2], freq[3]);
        freq[3] = min(freq[3], freq[2]);
        string plc;
        bool ndeu1 = true, ndeu2 = true;
        fr(i, freq[0]){
            ndeu1 = false;
            plc.pb('U');
        }
        fr(i, freq[2]){
            ndeu2 = false;
            plc.pb('R');
        }
        fr(i, freq[1]){
            plc.pb('D');
        }
        fr(i, freq[3]){
            plc.pb('L');
        }
        if(ndeu1 && !ndeu2){
            plc.clear();
            plc = "RL";
        }
        else if(ndeu2 && !ndeu1){
            plc.clear();
            plc = "UD";
        }
        cout << plc.size() << endl;
        cout << plc << endl;
    }
}
