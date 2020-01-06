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
const int N = 2e5 + 10;

int n, x[N], qnt[N], qntc[N];

int main(){
    scanf("%d", &n);
    frr(i, n) scanf("%d", &x[i]), qnt[x[i]]++, qntc[x[i]]++;
    
    int mx = 0, mn = 0;
    for(int i = 0; i <= n+1; i++){
        if(!qnt[i]){
            if(i == 0){
                if(qnt[1]){
                    qnt[1]--;
                    mx++;
                }
            }
            else if(i == n + 1){
                if(qnt[n] > 1){
                    mx++;
                }
            }
            else{
                if(qnt[i-1] > 1){
                    qnt[i]++;
                    mx++;
                }
                else if(qnt[i+1]){
                    qnt[i+1]--;
                    mx++;
                }
            }
        }
        else{
            mx++;
            if(qnt[i] > 1){
                qnt[i+1]++;
                qnt[i]--;
            }
        }
    }
    bool md = false;
    for(int i = 1; i <= n+1; i++){
        if(md){
            mn++;
            md = false;
            continue;
        }
        if(qntc[i]){
            if(i == 1){
                md = true;
                qntc[i+1] += qntc[i];
            }
            else{
                if(qntc[i-1]){
                    qntc[i-1] += qntc[i];
                    qntc[i] = 0;
                }
                else{
                    md = true;
                    qntc[i+1] += qntc[i];
                }
            }
        }
    }
    printf("%d %d\n", mn, mx);
}
