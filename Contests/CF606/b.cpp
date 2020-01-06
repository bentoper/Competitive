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

multiset<int> mset;
int n;

void del(){
    auto it = mset.rbegin();
    int val = (*it)/2;
    mset.erase(*it);
    if(val%2) return;
    mset.insert(val);
}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans = 0;
        fr(i, n){
            rvr(a);
            if(a%2 == 0 && mset.find(a) == mset.end()) mset.insert(a);
        }
        while(!mset.empty()){
            ans++;
            del();
        }
        printf("%d\n", ans);
    }
}
