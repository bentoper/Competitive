#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

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

int pos[111], used[111];

int main(){
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        ms(used, 0);
        vi v;
        fr(i, n){
            int a; cin >> a;
            v.pb(a);
            pos[a] = i;
        }
        int j = 0, curr = 1, i = 0;
        while(i < n - 1 && curr < n){
            int k = pos[curr++];
            if(k == 0) continue;
            if(used[k - 1] || v[k - 1] < v[k]) {continue;}
            while(k > 0 && !used[k - 1] && v[k] < v[k-1]){
                used[k - 1] = 1;
                swap(v[k], v[k-1]);
                swap(pos[v[k]], pos[v[k-1]]);
                k--;
                i++;
                if(!(i < n - 1)) goto vaca;
            }
        }
    vaca:
        fr(i, n){
            cout << v[i] << " \n"[i == n-1];
        }
    }
}
