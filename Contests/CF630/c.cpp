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
    fastio;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if(k == 1){
            vi a(26, 0);
            fr(i, n) a[s[i]-'a']++;
            int ans = INF;
            fr(i, 26){
                ans = min(ans, n - a[i]);
            }
            printf("%d\n", ans);
            continue;
        } 
        vi qnt(26, 0);
        int ans = 0;
        fr(i, (k+1)/2){
            int l = i, r = k -(i+1);
            fr(i, 26) qnt[i] = 0;
            while(r <= n-1){
                if(l != r) qnt[s[l]-'a']++, qnt[s[r]-'a']++;
                else qnt[s[l] - 'a']++;
                l += k;
                r += k;
            }

            int plc;
            plc = (n/k);
            if(l != r) plc *= 2; 
            int sm = plc;
            fr(j, 26){
                sm = min(sm, plc - qnt[j]);
            }
            ans += sm;
        }
        printf("%d\n", ans);
        

    }
}
