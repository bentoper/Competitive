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
const int N = 3e5 + 2;

int ans[N];

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        deque<int> dq;
        int pos = 0;
        int n = s.size();
        fr(i, n){
            if(i == 0) {dq.push_back(s[i]-'0'); continue;}
            int cur = s[i] - '0';
            int sz = dq.size();
            if(dq.front()%2 != cur%2){
                while(!dq.empty() && cur > dq.front()){
                    ans[pos++] = dq.front();
                    dq.pop_front();
                }
                if(dq.empty()) dq.push_back(cur);
                else ans[pos++] = cur;
            }
            else dq.push_back(cur);
        }
        while(!dq.empty()){
            ans[pos++] = dq.front();
            dq.pop_front();
        }
        fr(i, pos) printf("%d", ans[i]);
        printf("\n");
    }
}
