//https://community.topcoder.com/stat?c=problem_statement&pm=6742&rd=10763
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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n, aa, bb;

class KnapsackProblem{

    public:

    int numberOfWays(vector <int> x, int C){
        vector<int> a, b;
        vector<ll> l, r;
        ll ans = 0;
        n = x.size();
        fr(i, n/2 + n%2){
            a.pb(x[i]);
        }
        for(int i = n/2 + n%2; i < n; i++){
            b.pb(x[i]);
        }
        aa = a.size();
        bb = b.size();
        fr(i, 1<<aa){
            l.pb(0ll);
            fr(j, aa){
                if(i&(1<<j)){
                    l[i] += (ll)a[j]; 
                }
            }
        }
        fr(i, 1<<bb){
            r.pb(0ll);
            fr(j, bb){
                if(i&(1<<j)){
                    r[i] += (ll)b[j]; 
                }
            }
        }
        sort(r.begin(), r.end());
        for(auto s: l){
            if(s > C) continue;
            int pos = upper_bound(r.begin(), r.end(), C - s) - r.begin();
            if(pos == n){
                ans += n;
                continue;  
            }
            ans += pos;
        }
        return ans;
    }
};

