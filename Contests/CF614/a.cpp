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
    int t; scanf("%d", &t);
    while(t--){
        int n, s, k; scanf("%d%d%d", &n ,&s, &k);
        vi closed;
        fr(i, k){
            rvr(a); closed.pb(a);
        }
        sort(all(closed));
        int pos = lower_bound(all(closed), s) - closed.begin();
        if(pos == k || closed[pos] != s){
            printf("0\n");
            continue;
        }
        int j = pos, dist = 1;
        bool deu = false;
        while(j + dist <= k || j - dist >= -1){
            if((j + dist >= k && s + dist <= n) || (j + dist < k && closed[j+dist] != s + dist)){
                printf("%d\n", dist);
                deu = true;
                break;
            }
            if((j - dist <= -1 && s - dist >= 1) || (j - dist >= 0 && closed[j-dist] != s - dist)){
                printf("%d\n", dist);
                deu = true;
                break;
            }
            dist++;
        }
    }
}
