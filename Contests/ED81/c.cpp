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

vi pos[26];
bool freq[26];

int main(){
    int T; cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        ms(freq, false);
        fr(i, 26) pos[i].clear();
        int ss = s.size(), tt = t.size();
        fr(i, ss){
            pos[s[i]-'a'].pb(i);
            freq[s[i]-'a'] = true;
        }
        bool deu = true;
        fr(i, tt){
            if(!freq[t[i]-'a']){
                deu = false;
                break;
            }
        }
        if(!deu){
            printf("-1\n");
            continue;
        }
        int i = 0, ans = 0;
        while(i < tt){
            int cur = pos[t[i]-'a'][0];
            ans++;
            do{
                i++;
                if(i == tt) break;
                cur = upper_bound(all(pos[t[i]-'a']), cur) - pos[t[i]-'a'].begin(); 
                if(cur == pos[t[i]-'a'].size()){
                    break;
                }
                else cur = pos[t[i]-'a'][cur];
            }while(1);
        }
        printf("%d\n", ans);
    }
}
