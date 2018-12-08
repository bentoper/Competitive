#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define pq priority_queue
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

const unsigned long long int INF = 18446744073709551615;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int visited[100001];
unsigned long long int dist[100001];
vector<pair<ll, ll>> w[100001];
int path[100001];

void dijkstra(){
    pq<pair<ll, ll>> q;
    q.push(mp(0, 1));
    dist[1] = 0;
    while(!q.empty()){
        ll v = q.top().second;
        q.pop();
        if(visited[v]) continue;
        visited[v] = 1;
        for(pair<ll, ll> u: w[v]){
            if(dist[u.first] >= dist[v] + u.second){
                dist[u.first] = dist[v] + u.second;
                q.push(mp(-dist[u.first], u.first));
                path[u.first]= v;

            }
        }
        w[v].clear();
    }
}


int main(){
    ll n, m;
    cin >> n >> m;
    fr(i, n+1) dist[i] = INF;
    fr(i, m){
        ll a, b, p;
        cin >> a >> b >> p;
        if(a == b) continue;
        w[a].pb(mp(b, p)); w[b].pb(mp(a, p));
    }
    fr(i, n+1){
        sort(w[i].begin(), w[i].begin()+w[i].size());
        int c = 0, k = w[i].size();
        while(c + 1 < k){
            if(w[i][c].first == w[i][c+1].first){
                w[i].erase(w[i].begin()+(c+1));
                k--;
            }
            c++;
        }
    }
    dijkstra();
    if(path[n] == 0){
        cout << "-1" << endl;
        return 0;
    }
    stack<int> answ;
    while(path[n] != 1){
        answ.push(path[n]);
        path[n] = path[path[n]];
    }
    answ.push(1);
    while(!answ.empty()){
        cout << answ.top() << " ";
        answ.pop();
    }
    cout << n << endl;
}
