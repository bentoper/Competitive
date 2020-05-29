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
    int x, y, a, b, c; scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
    vi red, green, white;
    fr(i, a){
        rvr(aa);
        red.pb(aa);
    }
    fr(i, b){
        rvr(bb);
        green.pb(bb);
    }
    fr(i, c){
        rvr(cc);
        white.pb(cc);
    }
    sort(all(red));
    reverse(all(red));
    sort(all(green));
    reverse(all(green));
    sort(all(white));
    reverse(all(white));
    while(red.size() > x){
        red.pop_back();
    }
    while(green.size() > y){
        green.pop_back();
    }
    reverse(all(red));
    reverse(all(green));
    ll ans = 0;
    fr(i, x){
        ans += (ll)(red[i]);
    }
    fr(i, y) ans += (ll)(green[i]);
    int i = 0, j = 0, k = 0;
    bool end = false;
    while(i < x && j < y && k < c){
        if(red[i] < green[j]){
            if(white[k] > red[i]){
                ans += (ll)(white[k] - red[i]);
                k++;
                i++;
            }
            else{
                end = true;
                break;
            }
        }
        else{
            if(white[k] > green[j]){
                ans += (ll)(white[k] - green[j]);
                k++;
                j++;
            }
            else{
                end = true;
                break;
            }
        }
    }
    while(!end && i < x && k < c && white[k] > red[i]){
        ans += (ll)(white[k] - red[i]);
        k++;
        i++;
    }
    while(!end && j < y && k < c && white[k] > green[j]){
        ans += (ll)(white[k] - green[j]);
        k++;
        j++;
    }
    printf("%lld\n", ans);
}
