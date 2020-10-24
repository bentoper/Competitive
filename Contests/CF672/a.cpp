#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)


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
    tsts(t){
        rvr(n);
        vi a(n);
        fr(i, n) scanf("%d", &a[i]);
        vi b(a);
        sort(all(b));
        reverse(all(b));
        bool deu = true;
        fr(i, n - 1){
            if(a[i] > a[i+1]){
                deu = false;
                break;
            }
        }
        if(deu){
            printf("YES\n");
            goto END;
        }
        fr(i, n){
            if(a[i] != b[i] || (i < n - 1 && b[i] == b[i+1])){
                printf("YES\n");
                goto END;
            }
        }
        printf("NO\n");
        END:;
    }
}
