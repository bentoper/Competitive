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
const int N = 2e5 + 1;


int freq[N][200], pointers[200], cnt[200];
int v[N];

int qrg(int i, int j){
    int mx = -1;

    fr(k, 200){
        mx = max(mx, freq[j-1][k] - freq[i][k]);
    }
    return mx;
}

int main(){
    rvr(t);
    while(t--){
        int n; scanf("%d",  &n);
        fr(i, n){
            if(i){
                fr(j, 200) freq[i][j] = freq[i-1][j];
            }
            else{
                fr(j, 200) freq[i][j] = 0, pointers[j] = 0, cnt[j] = 0;
            }
            rvr(a);
            a--;
            freq[i][a]++;
            v[i] = a;
        }
        int ans = -1;
        for(int i = n-1; i >= 0; i--){
            cnt[v[i]]++;
            if(pointers[v[i]] >= i) continue;
            while(pointers[v[i]] < i && freq[pointers[v[i]]][v[i]] < cnt[v[i]]){
                pointers[v[i]]++;
            }
            if(i > pointers[v[i]] && freq[pointers[v[i]]][v[i]] == cnt[v[i]]){
                ans = max(2*cnt[v[i]] + qrg(pointers[v[i]], i), ans);
            }
        }
        printf("%d\n", max(ans, 1));
    }
}
