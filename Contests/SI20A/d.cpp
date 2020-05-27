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
const int N = 2e5 + 1;

int memo[N][26], pref[N][26];
int cost[26][26], dist[26][26];
string s;
int n, k, m;


void dijkstra(int r){
    set<pii> S;
    dist[r][r] = 0;
    S.insert(mp(0, r));
    while(!S.empty()){
        int v = (*S.begin()).second, d = (*S.begin()).first;
        S.erase(S.begin());
        fr(i, m){
            int c = cost[v][i];
            if(dist[r][i] == -1){
                S.insert(mp(d + c, i));
                dist[r][i] = d + c;
            }
            else if(dist[r][i] > d + c){
                S.erase(mp(dist[r][i], i));
                S.insert(mp(d + c, i));
                dist[r][i] = d + c;
            }
        }
    }
}

int dp(int i, int l){
    if(i == n) return 0;
    if(memo[i][l] != -1) return memo[i][l];
    memo[i][l] = INF;
    if(i == 0){
        fr(c, m){
            int plc = dp(i + k, c);
            if(plc == INF) continue;
            memo[i][l] = min(memo[i][l], plc + pref[k - 1][c]);
        }
    }
    else{
        if(n - i < k){
            memo[i][l] = pref[n - 1][l] - pref[i-1][l];
        }
        else{
            fr(c, m){
                if(c == l) continue;
                int plc = dp(i + k, c);
                if(plc == INF) continue; 
                memo[i][l] = min(memo[i][l], plc + pref[k + i - 1][c] - pref[i - 1][c]);
            }
            if(dp(i+1, l) != INF){
                memo[i][l] = min(memo[i][l], dp(i+1, l) + dist[s[i]-'a'][l]);
            }
        }

    }
    return memo[i][l];
}


int main(){
    cin >> n >> m >> k;
    cin >> s;
    fr(i, m){
        fr(j, m) cin >> cost[i][j];
    }
    ms(dist, -1);
    ms(memo, -1);
    fr(i, m) dijkstra(i);
    fr(i, n){
        if(i){
            fr(j, m){
                pref[i][j] = pref[i-1][j] + dist[s[i]-'a'][j];
            }
        }
        else{
            fr(j, m){
                pref[i][j] = dist[s[i]-'a'][j];
            }
        }
    }
    cout << dp(0, 0) << endl;
}
