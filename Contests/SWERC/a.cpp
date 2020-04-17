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

int T, N, B, c[111];

int memo[1111][111];

pii t, stations[1111];

vii adj[1111];

int dist(int a, int b){
    int x = stations[a].first - stations[b].first;
    int y =  stations[a].second - stations[b].second;
    return ceil(sqrt(x*x + y*y));
}

int dp(int i, int l){
    if(i == N + 1 && l >= 0) return 0;
    if(l < 0) return INF;
    if(memo[i][l] != -1) return memo[i][l];
    memo[i][l] = INF;
    for(auto p: adj[i]){
        int plc = dp(p.first, l - dist(i, p.first)); 
        if(plc != INF){
            memo[i][l] = min(memo[i][l], c[p.second]*dist(i, p.first) + plc);
            //printf("i %d v %d plc %d memo %d\n", i, p.first, plc, memo[i][l]);
        }
    }
    if(dist(i, N+1) <= l){
        memo[i][l] = min(memo[i][l], c[0]*dist(i, N+1));
    }
    return memo[i][l];
}

int main(){
    ms(memo, -1);
    scanf("%d%d", &(stations[0].first), &(stations[0].second));
    scanf("%d%d", &(t.first), &(t.second));
    scanf("%d", &B);
    scanf("%d", &c[0]);
    scanf("%d", &T);
    frr(i, T) scanf("%d", &c[i]);
    scanf("%d", &N);
    frr(i, N){
        scanf("%d%d", &stations[i].first, &stations[i].second);
        int l; scanf("%d", &l);
        fr(j, l){
            int idx, t; scanf("%d%d", &idx, &t);
            adj[i].pb(mp(idx+1, t));
            adj[idx+1].pb(mp(i, t));
        }
        adj[0].pb(mp(i, 0));        
    }
    adj[0].pb(mp(N+1, 0));
    stations[N+1] = t;
    int plc = dp(0, B);
    if(plc == INF) printf("-1\n");
    else printf("%d\n", plc);
}
