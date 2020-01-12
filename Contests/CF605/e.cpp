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
const int N = 2e5 + 1;

int a[N], n, dist[N], ans[N];

vi invadj[N];

vi odvec, evec;

queue<int> ev, od;

void oddfs(){
    while(!ev.empty()){
        int v = ev.front();
        ev.pop();
        for(auto u: invadj[v]){
            if(dist[v] + 1 < dist[u]){
                dist[u] = dist[v] + 1;
                ev.push(u);
            }
        }
    }
}

void evfs(){
    while(!od.empty()){
        int v = od.front();
        od.pop();
        for(auto u: invadj[v]){
            if(dist[v] + 1 < dist[u]){
                dist[u] = dist[v] + 1;
                od.push(u);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    ms(dist, INF);
    fr(i, n){
        scanf("%d", &a[i]);
        if(a[i]%2) od.push(i), odvec.pb(i);
        else ev.push(i), dist[i] = 0, evec.pb(i);
        if(i - a[i] >= 0){
            invadj[i - a[i]].pb(i);
        }
        if(a[i] + i < n){
            invadj[i + a[i]].pb(i);
        } 
    }
    oddfs();
    for(auto i: odvec){
        ans[i] = dist[i];
        if(ans[i] == INF) ans[i] = -1;
    }
    ms(dist, INF);
    for(auto i: odvec) dist[i] = 0;
    evfs();
    for(auto i: evec){
        ans[i] = dist[i];
        if(ans[i] == INF) ans[i] = -1;
    }
    pv(ans, n);
}