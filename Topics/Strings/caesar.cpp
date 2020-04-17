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

vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    int t; cin >> t;
    while(t--){
        string A, W, S;
        cin >> A >> W >> S;
        string plc;
        map<char, int> M;
        plc.append(W);
        plc.pb('&');
        plc.append(S);
        int alpha = A.size();
        fr(i, alpha) M[A[i]] = i;
        int ws = W.size(), ss = S.size();
        vi z;
        vi ans;
        fr(i, alpha){
            fr(j, ws) plc[j] = A[(M[plc[j]] + (i>0))%alpha]; 
            //cout << "plc " << plc << endl;
            z = z_function(plc);
            //vp(z);
            int cnt = 0;
            for(int k = ws + 1; k < ws + 1 + ss; k++){
                if(z[k] == ws) cnt++;
                if(cnt == 2) break;
            }
            //printf("cnt %d\n", cnt);
            if(cnt == 1) ans.pb(i);
        }
        if(ans.size() == 1){
            cout << "unique: " << ans[0] << endl;
        }
        else if(ans.size() >= 2){
            cout << "ambiguous: ";
            int aaaa = ans.size();
            fr(i, aaaa) cout << ans[i] << " \n"[i==aaaa-1];
        }
        else cout << "no solution" << endl;
    }
}
