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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 112345;
int n, curr, used[N], pos = 1;

vi perm;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        pos = 1;
        bool cagou = false;
        perm.clear();
        scanf("%d", &n);
        curr = -1;
        frr(i, n) used[i] = 0;
        fr(i, n){
            int q; scanf("%d", &q);
            if(i == 0){
                perm.pb(q);
                curr = q;
                used[q] = 1;
            }
            else{
                if(q > curr){
                    used[q] = 1;
                    curr = q;
                    perm.pb(q);
                }
                else{
                    while(pos <= n && used[pos]){
                        pos++;
                    }
                    if(pos > curr){
                        cagou = true;
                    }
                    else{
                        perm.pb(pos);
                        used[pos] = 1;
                    }
                }
            }
        }
        if(cagou){
            printf("-1\n");
        }
        else{
            fr(i, n){
                printf("%d%c", perm[i], " \n"[i==n-1]);
            }
        }
    }
}
