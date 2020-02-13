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

set<int> adj[26];
int vis[26];
string alpha;

void build(int r){
    alpha.push_back('a' + r);
    vis[r] = 1;
    for(auto v: adj[r]){
        if(vis[v]) continue;
        build(v);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        alpha.clear();
        fr(i, 26) adj[i].clear();
        ms(vis, 0);
        bool deu = true;
        fr(i, s.size() - 1){
            adj[s[i]-'a'].insert(s[i+1]-'a');
            adj[s[i+1]-'a'].insert(s[i]-'a');
            if(adj[s[i]-'a'].size() > 2 || adj[s[i+1]-'a'].size() > 2) deu = false;
        }
        if(s.size() == 1){
            cout << "YES\nabcdefghijklmnopqrstuvwxyz\n";
            continue;
        }
        if(!deu){
            cout << "NO\n";
            continue;
        }
        deu = false;
        fr(i, 26){
            if(adj[i].size() == 1){
                build(i);
                deu = true;
                break;
            }
        }
        if(!deu){
            cout << "NO\n";
            continue;
        }
        fr(i, 26) if(!vis[i]) alpha.push_back(i +'a');
        cout << "YES\n" << alpha << endl;
    }
}
