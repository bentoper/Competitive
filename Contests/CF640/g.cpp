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

vi md[1001];
int sz[4];

int main(){

    md[0] = {3, 1, 4, 2};
    md[1] = {1, 4, 2, 5, 3};
    md[2] = {1, 4, 2, 5, 3, 6};
    md[3] = {5, 1, 3, 6, 2, 4, 7};
    for(int i = 8; i <= 1000; i++){
        if(i%4 == 0){
            md[i - 4] = md[i - 8];
            fr(j, 4){
                md[i-4].pb(md[i-4][(i - 5) - j] + 4);
            }
        }
        else if(i%4 == 1){
            md[i-4] = md[i-5];
            md[i-4].pb(i);
        }
        else if(i%4 == 2){
            md[i-4] = md[i-6];
            md[i-4].pb(i-1);
            md[i-4].pb(i);
            if((i/4)%2) swap(md[i-4][i-1], md[i-4][i-5]);
            else swap(md[i-4][i-1], md[i-4][i-4]);
        }
        else if(i%4 == 3){
            md[i-4] = md[i-5];
            md[i-4].pb(i);
            if((i/4)%2 == 0){
                swap(md[i-4][i- 1], md[i-4][i- 4]);
                swap(md[i-4][i - 5], md[i-4][i- 6]);
            }
            else{
                swap(md[i-4][i - 4], md[i-4][i- 5]);
                swap(md[i-4][i - 1], md[i-4][i- 4]);
                swap(md[i-4][i - 7], md[i-4][i- 5]);
            }
        }
    }
    rvr(t);
    while(t--){
        rvr(n);
        if(n<=3){
            printf("-1\n");
            continue;
        }
        vp(md[n-4]);
    }

}
