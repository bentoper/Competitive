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

int freq[30];

int main(){
    int k; cin >> k;
    while(k--){
        ms(freq, 0);
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        fr(i, n){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']++;
        }
        bool cagou = false;
        fr(i, 26) if(freq[i]%2 != 0) cagou = true;
        if(cagou){
            cout << "No\n";
            continue;
        }
        vii ans;
        fr(i, n){
            if(t[i] != s[i]){
                bool deu = false;
                for(int j = i + 1; j < n; j++){
                    if(s[j] == s[i]){
                        ans.pb(mp(j+1, i+1));
                        swap(s[j], t[i]);
                        deu = true;
                        break;
                    }
                }
                if(!deu){
                    for(int j = i + 1; j < n; j++){
                        if(t[j] == s[i]){
                            ans.pb(mp(n, j+1));
                            ans.pb(mp(n, i+1));
                            swap(s[n-1], t[j]);
                            swap(s[n-1], t[i]);
                            break;
                        }
                    }
                }
            }
        }
        cout << "Yes\n";
        cout << ans.size() << "\n";
        fr(i, ans.size()){
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }

}
