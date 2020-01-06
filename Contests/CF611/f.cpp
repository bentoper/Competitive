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
const int N = 2e5 + 1;

int a[N], used[N], freq[N];

int main(){
    int n; scanf("%d", &n);
    fr(i, n-1){
        scanf("%d", &a[i]);
        used[a[i]] = 1;
        freq[a[i]]++;
    }
    int r = a[0];
    priority_queue<pii> pq;
    frr(i, n){
        if(!used[i]){
            pq.push(mp(-i, i));
        }
    }
    int i = n - 2;
    printf("%d\n", r);
    while(i >= 0 && !pq.empty()){
        int v = pq.top().second, pri = -(pq.top().first);
        pq.pop();
        printf("%d %d\n", a[i], v);
        if(--freq[a[i]] == 0) pq.push({-max(pri, a[i]), a[i]});
        i--;
    }
}
