#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])

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

int quad[4], lim[4];
int n, s1, s2;


int main(){
    scanf("%d%d%d", &n, &s1, &s2);
    fr(i, n){
        int a, b; scanf("%d%d", &a, &b);
        if(a > s1 && b > s2) quad[0]++;
        else if(a < s1 && b > s2) quad[1]++;
        else if(a < s1 && b < s2) quad[2]++;
        else if(a > s1 && b < s2) quad[3]++;
        else if(a == s1 && b > s2) lim[1]++;
        else if(a < s1 && b == s2) lim[2]++;
        else if(a == s1 && b < s2) lim[3]++;
        else if(a > s1 && b == s2) lim[0]++;
    }
    int mx = -1, xx, yy;
    int q[4];
    fr(i, 4){
        q[i] = quad[i] + quad[(i+1)%4] + lim[(i+1)%4];
        mx = max(mx, q[i]);
    }
    fr(i, 4){
        if(q[i] == mx){
            if(i == 0){
                xx = s1;
                yy = s2 + 1;
            }
            else if(i == 1){
                xx = s1 - 1;
                yy = s2;
            }
            else if(i == 2){
                xx = s1;
                yy = s2 - 1;
            }
            else{
                xx = s1 + 1;
                yy = s2;
            }
        }
    }
    printf("%d\n%d %d\n", mx, xx, yy);
    
}
