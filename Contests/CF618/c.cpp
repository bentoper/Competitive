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
const int N =  1e5 + 1;

int arr[N], suf[N], pref[N];

int main(){
    rvr(n);
    fr(i, n){
        scanf("%d", &arr[i]);
        if(i == 0) pref[i] = ~arr[i];
        else pref[i] = pref[i-1] & ~arr[i];
    }
    int ans = INT_MIN, val = -1;
    fr(i, n){
        if(i == 0) suf[n - 1 - i] = ~arr[n - 1 - i];
        else suf[n - 1 - i] = suf[n - i] & ~arr[n - 1 - i];
        if(i == 0){
            ans = pref[n - 2]&arr[n-1];
            val = arr[n-1];
        }
        else if(i != n-1){
            ans = max(pref[n - i - 2]&arr[n-1-i]&suf[n - i], ans);
            if(ans == (pref[n - i - 2]&arr[n-1-i]&suf[n - i])) val = arr[n-i-1];
        }else{
            ans = max(ans, arr[0]&suf[1]);
            if((arr[0]&suf[1]) == ans){
                val = arr[0];
            }
        }
    }
    fr(i, n){
        if(val == arr[i]){
            swap(arr[0], arr[i]);
            break;
        }
    }   
    pv(arr, n);
}
