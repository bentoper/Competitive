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
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
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
        string vaca, rev;
        for(int j = st, i = 0; i < plc; i++){
            vaca.push_back(s[j + i]);
        }
        int sz = vaca.size();
        fr(i, sz){
            rev.push_back(vaca[sz - 1 - i]);
        }
        vaca.pb('&');
        vaca.append(rev);
        vi z = z_function(vaca);
        int ans = -1, mode = 0;
        fr(i, sz){
            if(z[i + sz + 1] == sz - i){
                ans = i;
                break;
            }
        }
        //cout << "vaca " << vaca << endl;
        string vaca2;
        vaca2.append(rev);
        reverse(all(rev));
        vaca2.pb('&');
        vaca2.append(rev);
        //cout << "vaca2 " << vaca2 << endl;

        z = z_function(vaca2);
        fr(i, sz){
            if(z[i + sz + 1] == sz - i && sz - i > sz - ans){
                ans = i;
                mode = 1;
                break;
            }
        }
        fr(i, st){
            cout << s[i];
        }
        if(mode){
            for(int j = st + plc - 1, i = 0; i < sz - ans; i++){
                cout << s[j-i];
            }
        }
        else{
            for(int j = st, i = 0; i < sz - ans; i++){
                cout << s[j+i];
            }
        }
        fr(i, st) cout << s[st - 1 - i];
        cout << endl;
    }
}
