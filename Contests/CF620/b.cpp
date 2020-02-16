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

map<string, int> st;
map<string, int> eq;

int main(){
    int n, m; cin >> n >> m;
    vector<string> strings;
    fr(i, n){
        string plc; cin >> plc;
        st[plc]++;
    }
    int sz = n*m;
    set<string> inserted;
    string prefix, sufix, mid;
    for(auto p: st){
        string s = p.first;
        reverse(all(s));
        string rev = s;
        reverse(all(s));
        while(st[s] > st[rev]){
            sz -= m;
            st[s]--;
        }
        while(st[rev] > st[s]){
            sz -= m;
            st[rev]--;
        }

        if(rev == s && st[s]%2 == 1){
            eq[s] = st[s];
            continue;
        }
        if(st[s] > 0 && inserted.count(s) == 0){
            inserted.insert(s);
            inserted.insert(rev);
            string plc, plc1;
            fr(i, st[s]) plc.append(s), plc1.append(rev);
            prefix.append(plc), sufix.append(plc);
        }
    }
    if(eq.size() > 1){
        auto it = eq.begin();
        int mxsz = -1;
        string ans;
        while(it != eq.end()){
            if((*it).second > mxsz){
                mxsz = (*it).second;
                ans = (*it).first;
            }
            it++;
        }
        it = eq.begin();
        while(it != eq.end()){
            if((*it).first != ans){
                sz -= m*(*it).second;
            }
            it++;
        }
        fr(i, mxsz) mid.append(ans);
    }
    else if(eq.size() == 1) mid.append((*(eq).begin()).first);
    cout << sz << endl;
    reverse(all(sufix));
    cout << prefix << mid << sufix << endl;

}
