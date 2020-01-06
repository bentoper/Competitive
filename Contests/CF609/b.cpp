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
const int N  = 2e3 + 1;
int a[N], b[N];

int main(){
    int n, m; scanf("%d%d", &n, &m);
    fr(i, n){
        scanf("%d", &a[i]);
    }
    fr(i, n){
        scanf("%d", &b[i]);
    }
    sort(a, a+n);
    sort(b, b+n);
    vii qnta; 
    vi qntb;
    fr(i, n){
        int cnt = 1, j = i;
        while(i < n-1 && a[i] == a[i+1]){
            i++;
            cnt++;
        }
        qnta.pb(mp(cnt, j));
    }
    fr(i, n){
        int cnt = 1;
        while(i < n-1 && b[i] == b[i+1]){
            i++;
            cnt++;
        }
        qntb.pb(cnt);
    }
    int plc  = qnta.size();
    fr(i, plc){
        qnta.pb(qnta[i]);
    }
    int mn = INF, sz = qntb.size();
    fr(i, sz){
        int j = 0;
        while(j < sz && qntb[j] == qnta[i+j].first){
            j++;
        }
        if(j == sz){
            int aa = a[qnta[i].second], val = (b[0] + m - aa)%m;
            bool deu = true;
            fr(k, n){
                if((a[(qnta[i].second+k)%n] + val)%m != b[k]){
                    deu =false;
                    break;
                }
            } 
            if(deu) mn = min(mn, val);
        }
    }
    printf("%d\n", mn);
}
