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
const int N = 4e5 + 2;

int pref[N], cnt[N];

int main(){
    rvr(t);
    while(t--){
        rvr(n); 
        rvr(k);
        vi v;
        fr(i, 2*k + 1) cnt[i] = 0, pref[i] = 0;
        fr(i, n){
            rvr(a);
            v.pb(a);
        }
        fr(i, n/2){
            pref[min(v[i], v[n-1-i]) + 1]++;
            pref[max(v[i], v[n-1-i]) + k + 1]--;
            cnt[v[i] + v[n-1-i]]++;
        }
        frr(i, 2*k) pref[i] += pref[i-1];
        int mn = INF;

        frr(i, 2*k) mn = min(mn, pref[i] - cnt[i] + 2*(n/2 - pref[i]));
        printf("%d\n", mn);
    }
}
