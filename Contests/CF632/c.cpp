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

int main(){
    vi a;
    vll sm;
    rvr(n);
    fr(i, n){
        rvr(aa);
        a.pb(aa);
        if(!i) sm.pb(aa);
        else sm.pb(sm[i-1] + (ll)(aa));
    }
    queue<ll> q;
    set<ll> s;
    ll ans = 0;
    int tam = 0;
    queue<int> values;
    ll cursum = 0;
    fr(i, n){
        cursum += (ll) a[i];
        values.push(a[i]);
        q.push(sm[i]);
        if(a[i] == 0){
            cursum = 0;
            tam = 0;
            s.clear();
            while(!q.empty()) q.pop();
            while(!values.empty()) values.pop();
            continue;
        }
        if(s.count(sm[i]) != 0){
            while(q.front() != sm[i]){
                s.erase(q.front());
                q.pop();
                cursum -= (ll)values.front();
                values.pop();
                tam--;
            }
            cursum -= (ll)values.front();
            values.pop();
            q.pop();
            if(cursum == 0){
                cursum -= (ll)values.front();
                s.erase(q.front());
                q.pop();
                values.pop();
                tam--;
            }
            ans += tam;
        }
        else if(cursum == 0){
            s.erase(q.front());
            cursum -= (ll)values.front();
            q.pop();
            values.pop();
            s.insert(sm[i]);
            ans += tam;
            continue;
        }
        else{
            s.insert(sm[i]);
            tam++;
            ans += tam;
        }
    }
    printf("%lld\n", ans);
}
