#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll memo[100001], n;

ll dp(ll mx){
    ll ans, pickedlast = 0;
    fr(i, mx+1){
        if(i == 0 || i == 1) continue;
        if(i == 2){
            if(memo[1] > memo[2]) ans = memo[1];
            else{
                ans = memo[2];
                pickedlast = 1;
            }
        }
        else{
            if(pickedlast){
                if(ans < ans - memo[i-1] + memo[i] + memo[i-2]){
                        ans = ans - memo[i-1] + memo[i] + memo[i-2];
                }
                else pickedlast = 0;
            }
            else{
                ans += memo[i];
                pickedlast = 1;
            }
        }
        memo[i] = ans;
    }
    return ans;
}

int main(){
    cin >> n;
    ll a, mx = 0;
    fr(i, n){
        cin >> a;
        memo[a] += a;
        mx = max(mx, a);
    }
    if(n == 1){
        cout << a << endl;
        return 0;
    }
    cout << dp(mx) << endl;
}
