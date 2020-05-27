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

int freq[26];

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        ms(freq, 0);
        fr(i, n) freq[s[i]-'a']++;
        string plc;
        sort(all(s));
        int i = 0, nk = k;
        if(s[k-1] != s[0]){
            cout << s[k-1] << endl;
            continue;
        }
        freq[s[0]-'a'] -= k;
        plc.pb(s[0]);
        fr(i, 26){
            fr(j, freq[i]/nk) plc.pb(i + 'a');
            if(freq[i]%nk == 0) continue;
            else{
                plc.pb(i + 'a');
                nk = freq[i]%nk;
            }
        }
        string vac;
        for(int i = k-1; i < n; i++){
            vac.pb(s[i]);
        }
        cout << min(plc, vac) << endl;
    }
}
