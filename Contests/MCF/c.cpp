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
const int N = 1123;

int a[N][N];
int n;

int main(){
	scanf("%d", &n);
    pii k[] = {mp(0, 0), mp(0, n/2), mp(n/2, 0), mp(n/2, n/2)};
    fr(l, 4){
        fr(i, n/2){
            fr(j, n/2){
                a[i+k[l].first][j+k[l].second] = (i*(n/2) + j)*4 + l;
            }
        }
    }
    fr(i, n){
        fr(j, n){
            printf("%d%c", a[i][j], " \n"[j==n-1]);
        }
    }

}




