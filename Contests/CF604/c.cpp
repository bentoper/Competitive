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
const int N = 4e5 + 1;

int p[N], n;
vi freq;


int main(){
    int t; scanf("%d", &t);
    while(t--){
        freq.clear();
        scanf("%d", &n);
        int cnt = 1;
        fr(i, n){
            scanf("%d", &p[i]);
            if(i > 0 && p[i] == p[i-1]) cnt++;
            else if(i > 0){
                freq.pb(cnt);
                cnt = 1;
            }
        }
        freq.pb(cnt);
        if(freq.size() < 3){
            printf("0 0 0\n");
            continue;
        }
        int posf = 0, sz = freq.size();
        int sm = 0;
        fr(i, sz){
            if(sm + freq[i] > n/2){
                posf = i;
                break;
            }
            sm += freq[i];
        }
        if(posf < 3){
            printf("0 0 0\n");
            continue;
        }
        int gold = freq[0];
        int j = 1, silver = 0;
        while(j < posf){
            silver += freq[j++];
            if(silver > gold) break;
        }
        if(silver <= gold || sm - (silver + gold) <= min(silver, gold)){
            printf("0 0 0\n");
            continue;
        }
        else printf("%d %d %d\n", gold, silver, sm - gold - silver);
    }
}
