#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define pv(x, n) fr(i, n) printf("%d%c",x[i], " \n"[i == n-1]);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x);
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
const int N = 212345;

int p[N];
int n;
int ml[N];
int cnt[N][3];

int S(int i, int r, int l){
    return cnt[r][i] - cnt[l - 1][i];
}

int main(){
    int k[3];
    fr(i, 3) {scanf("%d", &k[i]); n += k[i];}
    fr(i, 3){
        fr(j, k[i]){
            rvr(a);
            p[a] = i;
            cnt[a][i] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        fr(j, 3){
            cnt[i][j] += cnt[i-1][j];
        }
        ml[i] = S(1, i, 1) - S(0, i, 1); 
    }
    int idx = 0;
    ml[0] = 0;
    vi v;
    v.pb(0);
    frr(i, n) {
        if(ml[i] > ml[i-1]){
            ml[i] = ml[i-1];
        }
        else idx = i;
        v.pb(idx);
    }
    //pv(v, n+1);
    int ans = min(k[0] + k[1], min(k[0] + k[2], k[1] + k[2]));
    for(int r = 1; r <= n; r++){
        int l = v[r];
        ans = min(ans, S(2, r, 1) + S(1, l, 1) + S(1, n, r+1) + S(0, n, l+1));
    }
    printf("%d\n", ans);
}
