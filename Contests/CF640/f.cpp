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
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if(a > 0 && b > 0 && c > 0){
            if(b%2 == 0 && b > 1){
                printf("0");
            }
            b--;
            fr(i, b/2){
                printf("10");
            }
            fr(i, c+1) printf("1");
            fr(i, a+1) printf("0");
        }
        else if(b == 0){
            if(a == 0) fr(i, c+1) printf("1");
            else if(c == 0) fr(i, a+1) printf("0");
        }
        else if(a != 0){
            fr(i, a+1) printf("0");
            fr(i, b/2) printf("10");
            if(b%2) printf("1");
        }
        else if(c != 0){
            fr(i, c+1) printf("1");
            fr(i, b/2) printf("01");
            if(b%2) printf("0");
        }
        else{
            if(b == 1) printf("01");
            else if(b == 2) printf("010");
            else{
                if(b%2 == 0) printf("0");
                fr(i, (b+1)/2) printf("10");
            }
        }
        printf("\n");
    }
}
