//https://arena.topcoder.com/#/u/practiceCode/1665/5848/6449/1/1665
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

set<vi> m;
map<vi, int> g;

void build(vi curr){
    sort(all(curr));
    if(m.find(curr) != m.end()) return;
    int sz = curr.size();
    m.insert(curr);
    for(int i = 0; i < sz; i++){
        int val = curr[i];
        if(i > 0 && val == curr[i-1]) continue;
        swap(curr[i], curr[sz-1]);
        curr.pop_back();
        for(int j = i; j < sz - 1; j++){
            curr[j] += val;
            build(curr);
            curr[j] -= val;
        }
        curr.push_back(val);
        swap(curr[i], curr[sz-1]);
    }
}

int solve(vi curr){
    int sz = curr.size();
    sort(all(curr));

    if(m.find(curr) != m.end()){
        return sz;
    }
    
    if(g[curr]){
        return g[curr];
    }


    int ans = 0;
    for(int i = 0; i < sz; i++){
        int val = curr[i];
        if(i > 0 && val == curr[i-1]) continue;

        swap(curr[i], curr[sz-1]);
        curr.pop_back();
        for(int j = i; j < sz - 1; j++){
            curr[j] += val;
            ans = max(ans, solve(curr));
            curr[j] -= val;
        }
        curr.push_back(val);
        swap(curr[i], curr[sz-1]);
    }
    g[curr] = ans;
    return ans;    
}


class SplitAndMergeGame{
    
    public:
    
    int minMoves(vector <int> startState, vector <int> finishState){
        
        int sa = 0, sb = 0;
        fr(i, startState.size()) sa += startState[i];
        fr(i, finishState.size()) sb += finishState[i];

        if(sa != sb){
            return -1;
        }

        build(startState);
        return(startState.size() + finishState.size() - 2*solve(finishState));
    }
};

int main(){
    vi a = {33, 12, 17, 19, 22, 14}, b = {33 - 16, 12 + 5, 17 + 11, 6, 31, 18};
    SplitAndMergeGame t;
    cout << t.minMoves(a, b) << endl;
}