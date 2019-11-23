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
const int N = 112345;

int n, p[N], freq[N];
int ans[N];

set<int> adj[N];

int tups[N][3];

vi vaca[N];

int used[N], def[N];

void setfirst(int i){
    ans[0] = i;
    int tp = vaca[i][0]; 
    def[i] = 1;
    fr(j, 3){
        if(freq[tups[tp][j]] == 2){
            ans[1] = tups[tp][j];
        }
        else if(freq[tups[tp][j]] == 3){
            ans[2] = tups[tp][j];
        }
    }
    used[tp] = 1;
    def[ans[1]] = 1;
    def[ans[2]] = 1;
    int pos = 2;
    int k = 1;
    while(k < n){
        for(auto x: vaca[ans[k]]){
            if(used[x]) continue;
            int aa = tups[x][0], bb = tups[x][1], cc =tups[x][2]; 
            if(def[aa] + def[bb] + def[cc] == 2){
                if(!def[aa]){
                    ans[++pos] = aa;
                    def[aa] = 1;
                }
                else if(!def[bb]){
                    ans[++pos] = bb;
                    def[bb] = 1;
                }
                else if(!def[cc]){
                    ans[++pos] = cc;
                    def[cc] = 1;
                }
                used[x] = 1;
                break;
            }
        }
        k++;
    }
}

int main(){
    scanf("%d", &n);
    fr(i, n-2){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        tups[i][0] = a;
        tups[i][1] = b;
        tups[i][2] = c;
        vaca[a].pb(i);
        vaca[b].pb(i);
        vaca[c].pb(i);
        freq[a]++;
        freq[b]++;
        freq[c]++;
    }
    frr(a, n){
        if(freq[a] == 1){
            setfirst(a);
            break;
        }
    }

    fr(i, n){
        printf("%d%c", ans[i], " \n"[i==n-1]);
    }

}
