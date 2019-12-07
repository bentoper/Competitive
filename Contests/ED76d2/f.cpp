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
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define bip(x) __builtin_popcount(x) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;

map<vi, bool> vecs;
map<vi, int> id;

vi plc;
int l[101], r[101], ini[101];

int main(){
    
    scanf("%d", &n);

    fr(i, n){
        scanf("%d", &ini[i]);
        r[i] = ini[i] >> 15;
        
        l[i] = ini[i]^(r[i] << 15);
    }
    int amt;
    for(int i = 1<<15 - 1; i >= 0;i--){
        plc.clear();
        fr(j, n){
            if(j == 0) amt = bip(r[j]^i);  
            else plc.pb(amt - bip(r[j]^i));
        }
        //pv(plc, plc.size());
        vecs[plc] = true;
        id[plc] = i;
    }
    fr(i, 1<<15){
        plc.clear();
        fr(j, n){
            if(j == 0){
                amt = bip(l[0]^i);
            }
            else plc.pb(-(amt - bip(l[j]^i)));
        }
        if(vecs[plc]){
            //pv(plc, plc.size());
            int b = id[plc];
            int vaca = i;
            if(b){
                //printf("b = %d\n", b);
                vaca += (b << 15);
            }
            printf("%d\n", vaca);
            return 0;
        }
    }
    printf("-1\n");
}