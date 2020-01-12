#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(i, n) printf("%d%c", x[i], " \n"[i==n-1])
#define pvv(x, n)    frr(i, n) printf("%d%c", x[i], " \n"[i==n])
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
const int MAXN = 5e5 + 1;

int a[MAXN];
int n, q;
int hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN + 1];

vii current, dirty;

int update(int a, int b){
	return __gcd(a, b);
}

int build(int node, int start, int end){
	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = a[start];
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 
}

void query(int node, int start, int end){

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
        current.pb(mp(seg[node], node));
		return;
	}
    query(2*node, start, end);
    query(2*node+1, start, end);

}

void change(int node, int start, int end, int x){

	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
        seg[node] = x;
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}

bool solve(int node, int x){

    if(hi[node] == lo[node]) return true;
    if(seg[2*node]%x != 0 && seg[2*node + 1]%x != 0) return false;
    if(seg[2*node]%x != 0) return solve(2*node, x);
    else return solve(2*node + 1, x);
}

int main(){
    scanf("%d", &n);
    frr(i, n) scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    while(q--){
        int c; scanf("%d", &c);
        if(c == 1){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            query(1, l, r);
            bool deu = true;
            for(auto p: current){
                if(p.first%x == 0) continue;
                else{
                    deu = false;
                    dirty.pb(p);
                }
            }
            if(deu) printf("YES\n");
            else{
                if(dirty.size() >= 2) printf("NO\n");
                else{
                    if(solve(dirty[0].second, x)){
                        printf("YES\n");
                    }
                    else printf("NO\n");
                }
            }
            current.clear();
            dirty.clear();
        }
        else{
            int pos, x; scanf("%d%d", &pos, &x);
            change(1, pos, pos, x);
        }
    }
}
