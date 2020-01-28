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

bool deu[27];

int freq[27];

int main(){
    int t; cin >> t;
    while(t--){
        ms(freq, 0);
        ms(deu, false);
        string s; cin >> s;
        if(s.size() == 1){
            cout << s << endl;
            continue;
        }
        fr(i, s.size()){
            freq[s[i]-'a']++;
            if(i < s.size() - 1 && freq[s[i] -'a']%2 && s[i+1] != s[i]) deu[s[i]-'a'] = true;
            if(i == 0){
                if(s[1] != s[0]) deu[s[i]-'a'] = true;
            }
            else if(i == s.size() - 1){
                if(s[i-1] != s[i]) deu[s[i]-'a'] = true;
            }
            else{
                if(s[i-1] != s[i] && s[i+1] != s[i]) deu[s[i]-'a'] = true;
            }
        }
        fr(i, 26){
            if(deu[i] || freq[i]%2) cout << (char)('a' + i);
        }
        cout << endl;
    }
}
