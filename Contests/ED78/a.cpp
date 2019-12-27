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

string s;
int freq[27], freq1[27];


int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        string ss;
        cin >> s;
        ms(freq, 0);
        fr(i, s.size()){
            freq[s[i]-'a']++;
        }
        cin >> ss;
        if(ss.size() < s.size()){
            cout << "NO\n";
            continue;
        }
        bool cagou = true;
        for(int i = 0; i<= ss.size() - s.size(); i++){
            ms(freq1, 0);
            fr(j, s.size()) freq1[ss[i+j]-'a']++;
            bool deu = true;
            fr(j, 26) if(freq1[j] != freq[j]) deu = false;
            if(deu){
                cout << "YES\n";
                cagou = false;
                break;
            }
        }
        if(cagou){
            cout << "NO\n";
        }
    }
}
