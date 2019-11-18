#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

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

int freq[26], freq1[26];
int n;
int q;
string s, t;

int main(){
    fastio;
    cin >> q;
    while(q--){
        fr(i, 26){
            freq[i] = 0;
            freq1[i] = 0;
        }
        cin >> n;
        cin >> s >> t;
        ll invS1 = 0, invS2 = 0;
        fr(i, n){
            char a = s[i], b = t[i];
            int u = a - 'a', v = b - 'a';
            freq[u]++;
            freq1[v]++;
            for(int j = 25; j > min(u, v); j--){
                if(j > u) {
                    invS1 += (ll) freq[j];
                }
                if(j > v) {
                    invS2 += (ll) freq1[j];
                } 
            }
        }
        bool deu = true, fd = false;
        
        fr(i, 26){
            if(freq[i] != freq1[i]){
                deu = false;
            }
            if(freq[i] > 1){
                fd = true;
            }

        }
        if(!deu){
            cout << "NO\n";
            continue;
        }
        else{
            if(fd) cout << "YES\n";
            else if(invS2%2 == invS1%2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}
