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

map<pii, vi> M;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        pii cur = mp(0, 0);
        M.clear();
        M[cur].pb(0);
        int ans = INF;
        pii idxs = {0, 0};
        fr(i, n){
            if(s[i] == 'L'){
                cur = mp(cur.first - 1, cur.second);
            }
            else if(s[i] == 'R') cur = mp(cur.first + 1, cur.second);
            else if(s[i] == 'U') cur = mp(cur.first, cur.second + 1);
            else if(s[i] == 'D') cur = mp(cur.first, cur.second - 1);
            M[cur].pb(i+1);
        }
        for(auto p: M){
            if(p.second.size() > 1){
                int sz = p.second.size();
                fr(i, sz - 1){
                    if(p.second[i+1] - p.second[i] - 1 < ans){
                        idxs = mp(p.second[i] + 1, p.second[i+1]);
                        ans = p.second[i+1] - p.second[i] - 1;
                    }
                }
            }
        }
        if(ans == INF){
            cout << -1 << endl;
            continue;
        }
        cout << idxs.first << " " << idxs.second << endl;
    }
}
