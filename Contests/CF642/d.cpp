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

struct mycomp{
    bool operator() (const pii& a, const pii& b) const{
        if(a.second  - a.first > b.second - b.first) return true;
        if(a.second  - a.first < b.second - b.first) return false;
        return a.first < b.first;
    }
};

int main(){
    rvr(t);
    while(t--){
        rvr(n);
        vi a(n, 0);
        set<pii, mycomp> S;
        S.insert({0, n-1});
        int nxt = 1;
        while(!S.empty()){
            
            pii cur = *(S.begin());
            S.erase(S.begin());
            int idx = cur.second - cur.first + 1, pos;
            if(idx%2 == 0) pos = (cur.second + cur.first - 1)/2;
            else pos = (cur.second + cur.first)/2;
            a[pos] = nxt++;
            if(cur.first == cur.second) continue;
            if(cur.first <= pos - 1) S.insert({cur.first, pos-1});
            if(cur.second >= pos + 1) S.insert({pos + 1, cur.second}); 
        }
        vp(a);
    }
}
