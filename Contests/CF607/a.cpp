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
const ll mod = 1e9 + 7;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size(); 
        if((s[n-2] ==  'p' && s[n-1] == 'o')) cout << "FILIPINO\n";
        else if(((s[n-4] == 'd' && s[n-3] == 'e') || (s[n-4] == 'm' && s[n-3] == 'a')) && (s[n-2] ==  's' && s[n-1] == 'u')) cout << "JAPANESE\n";
        else cout << "KOREAN\n";
    }
}
