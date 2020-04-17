//https://www.hackerrank.com/contests/world-codesprint-april/challenges/gena/problem
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
#define gnl printf("\n");
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef stack<int> SI;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;

string tower = "";
string base = "";
string plc = "";
string cur = "";

map<string, int> dist;
map<string, bool> id;
queue<string> q;

int bfs(){
    dist[base] = 1;
    dist[tower] = 1;
    id[base] = 1;
    id[tower] = 0;
    q.push(base);
    q.push(tower);
    while(!q.empty()){
        cur.assign(q.front());
        q.pop();
        plc.assign(cur);
        int m[] = {11, 11, 11, 11};
        fr(i, n){
            int j = cur[i] - '1';
            m[j] = min(m[j], i);
        }
        fr(i, 4){
            fr(j, 4){
                if(i != j && m[i] < m[j]){
                    char sv = plc[m[i]];
                    plc[m[i]] = '1' + j;
                    if(dist[plc] == 0){
                        dist[plc] = dist[cur] + 1;
                        id[plc] = id[cur];
                        q.push(plc);
                    }
                    else{
                        if(id[plc]^id[cur]){
                            return dist[plc]+dist[cur]-1;
                        }
                    }
                    plc[m[i]] = sv;
                }
            }
        }
    }
    return INF;
}


int main(){
    scanf("%d", &n);
    frr(i, n) {
        rvr(a);
        tower.push_back((char)('1' + a - 1));
        base.push_back('1');
        plc.push_back('1');
        cur.push_back('1');

    }

    printf("%d\n", bfs());

}
