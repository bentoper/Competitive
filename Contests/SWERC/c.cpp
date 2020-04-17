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
const int N = 1000000;

int a[N+10];

int func(string s){
    int a = 0;
    int sz = s.size();
    fr(i, sz){
        a *= 10;
        a += s[i] - '0';
    }
    if(a < N) return a;
    return -1;
}

int main(){
    fastio;
    int n; cin >> n;
    fr(i, n){
        string s; cin >> s;
        if(s.size() > 7 || s[0] == '-') continue;
        int plc = func(s);
        if(plc == -1) continue;
        a[plc] = 1;         
    }
    fr(i, N){
        if(!a[i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;

}
