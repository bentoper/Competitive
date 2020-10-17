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
    rvr(n);
    vi a(n);
    int qnt = 0, qnt2 = 0, qnt3 = 0;
    fr(i, n){
        scanf("%d", &a[i]);
        if(a[i] == 2) qnt2++, qnt3 = 0;
        else if(a[i] == 1 && qnt2){
            qnt2--;
        }
        else if(a[i] == 1 && qnt3){
            qnt3 = 0;
        }
        else if(a[i] == 3) qnt3++; 
    }
    if(qnt2 || qnt3){
        printf("-1\n");
        return 0;
    }
    int nxt = 0, i = 0, av = n, inv = 0;
    vii ans;
    while(i < n){
        if(a[i] == 1){
            ans.pb(mp(i+1, av--));
        }
        else if(a[i] == 2){
            while(a[nxt] != 1) nxt++;
            ans.pb(mp(i+1, av));
            ans.pb(mp(nxt+1, av--));
            a[nxt] = 0;
        }
        else if(a[i] == 3){
            a[i] = 0;
            while(a[inv] == 0) inv++;
            int last = i;
            while(a[inv] != 1 && a[inv] != 2){
                a[last] = 0;
                if(a[inv] == 0){
                    inv++;
                    continue;
                }
                ans.pb(mp(last+1, av));
                ans.pb(mp(inv+1, av--));
                last = inv;
                a[last] = 0;
            }
            if(a[inv] == 1){
                ans.pb(mp(last+1, av));
                ans.pb(mp(inv+1, av--));
                ans.pb(mp(inv+1, av--));
                a[inv] = 0;
            }
            else{
                ans.pb(mp(last+1, av));
                ans.pb(mp(inv+1, av--));
                ans.pb(mp(inv+1, av));
                a[inv] = 0;
                while(a[nxt] != 1) nxt++;
                ans.pb(mp(nxt+1, av--));
                a[nxt] = 0;
            }
        }
        a[i++] = 0;
    }
    if(av < 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", (int)ans.size());
        for(auto p: ans){
            printf("%d %d\n", n - p.ss + 1, p.ff);
        }
    }
}

