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
const int N = 2e9;

vector<pii> ev, od;

void build(){
    ll sm = 1, i = 1;
    do{
        if(sm%2){
            od.pb(mp((int)sm, (int)i));
        }
        else ev.pb(mp((int)sm, (int)i));
        i++;
        sm = (i*(i+1))/2;
    }while(sm < N);
}

int main(){
    int t; cin >> t;
    build();
    while(t--){
        ll a, b;
        cin >> a >> b;
        int pos = 1;
        pii vw = mp((int)abs(a-b), 0);
        if(a-b == 0){
            cout << 0 << endl;
            continue;
        }
        if((a-b)%2 == 0){
            pos = lower_bound(all(ev), vw) - ev.begin();
            cout << ev[pos].second << endl;
            //dbg(ev[pos].first);
        } 
        else{
            pos = lower_bound(all(od), vw) - od.begin();
            cout << od[pos].second << endl;
        }
    }
}
