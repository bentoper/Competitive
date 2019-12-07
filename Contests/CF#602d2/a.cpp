#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], i==n-1);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define ss(x) scanf("%d", &x)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int minstart = INF, maxend = -1;

int n;

int main(){
    int t; ss(t);
    while(t--){
    ss(n);
    minstart = INF, maxend = -1;
    fr(i, n){
        int a, b; ss(a); ss(b);
        minstart = min(minstart, b);
        maxend = max(a, maxend);
    }
    printf("%d\n", max(0, maxend - minstart));
    }


}
