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

bool check(string s){
    int n = s.size();
    fr(i, n-1){
        if(s[i+1] == s[i]) return false;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        string s; cin >> s;
        n = s.size();
        fr(i, n){
            if(s[i] == '?'){
                int aval[] = {1, 1, 1};
                if(i > 0) aval[s[i-1]-'a'] = 0;
                if(i < n && s[i+1] != '?') aval[s[i+1]-'a'] = 0;
                fr(j, 3){
                    if(aval[j]){
                        s[i] = j + 'a';
                        break;
                    }
                }  
            }
        }
        if(check(s)){
            cout << s << endl;
        }
        else cout << -1 << endl;
    }
}
