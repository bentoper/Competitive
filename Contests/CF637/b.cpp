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
    rvr(t);
    while(t--){
        rvr(n);
        rvr(k);
        vi a(n);
        vector<bool> vec(n, false);
        fr(i, n) scanf("%d", &a[i]);
        int ans = -1, l = 0, cur = 0;
        int i = 0;
        while(i <= n-1 - (k-1)){
            if(!i){
                fr(j, k){
                    if(j && j != k-1){
                        if(max(a[j-1], a[j+1]) < a[j]) cur++, vec[j] = true;
                    }
                }
                if(ans < cur){
                    ans = cur;
                    l = i;
                }
            }
            else{
                if(vec[i]) cur--;
                if(max(a[i+k-3], a[i+k-1]) < a[i+k-2]){
                    vec[i+k-2] = true;
                    cur++;
                }
                if(ans < cur){
                    ans = cur;
                    l = i;
                }
            }
            i++;
        }
        printf("%d %d\n", ans+1, l+1);
    }
}
