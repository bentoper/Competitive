#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])

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
const int N = 555;

ll n, m, p[N], q[N], k[N];

string name[N];

map<string, string> PC;

set<string> hascar;

map<string, int> id;
map<string, ll> cost;

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        id.clear();
        cost.clear();
        hascar.clear();
        PC.clear();
        cin >> n >> m;
        fr(i, n){
            cin >> name[i] >> p[i] >> q[i] >> k[i];
            id[name[i]] = i;
        }
        fr(i, m){
            int tt; string s; char e;
            cin >> tt >> s >> e;
            if(e == 'p'){
                string car; cin >> car;
                if(cost[s] == -1) continue;
                if(hascar.find(s) != hascar.end()){
                    cost[s] = -1;
                }
                else{
                    PC[s] = car;
                    hascar.insert(s);
                    cost[s] += q[id[car]];
                }
            }
            else if(e == 'r'){
                ll d; cin >> d;
                if(cost[s] == -1) continue;
                auto it = hascar.find(s);
                if(it == hascar.end()){
                    cost[s] = -1;
                }
                else{
                    cost[s] += d*k[id[PC[s]]];
                    hascar.erase(it);
                }
            }
            else{
                ll per; cin >> per;
                if(cost[s] == -1) continue;
                if(hascar.find(s) == hascar.end()){
                    cost[s] = -1;
                }
                else{
                    if(cost[s] != -1){
                        int plc = p[id[PC[s]]]*per;
                        if(plc%(ll)100 != 0){
                            plc /= (ll)100;
                            plc++;
                        }
                        else plc /= (ll)100;
                        cost[s] += plc;
                    }
                }
            }
        }
        for(auto x: hascar){
            cost[x] = -1;
        }
        for(pair<string, int> p: cost){
            cout << p.first << " ";
            if(p.second == -1) cout << "INCONSISTENT\n";
            else cout << p.second << "\n";
        }
    }
}
