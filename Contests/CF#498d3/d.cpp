#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1]);

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define gnl printf("\n");
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string a, b;
int n;

int main(){
    cin >> n;
    cin >> a >> b;
    int mid = n/2;
    int ans = 0;
    fr(i, mid){
        char bn = b[n - i - 1], an = a[n - i - 1];
        map<char, int> frq;
        frq[bn]++; frq[an]++; frq[a[i]]++; frq[b[i]]++;
        if(frq.size() == 4){
            ans += 2;
        }
        else if(frq.size() == 3){
            ans += 1 + (a[i] == an);
        }
        else if(frq.size() == 2){
            ans += (frq[a[i]] != 2); 
        }
    }
    if(n%2){
        if(a[mid] != b[mid]) ans++;
    }
    cout << ans << endl;
}
