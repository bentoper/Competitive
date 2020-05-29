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

bool acomp(pii a, pii b){
    if(a.first < b.first) return true;
    if(a.first == b.first && a.second < b.second) return true;
    return false;
}


int main(){
    int a, b, t, ta, tb;
    scanf("%d%d%d%d%d", &a, &b, &t, &ta, &tb);
    vii tasks;
    int c; scanf("%d", &c);
    fr(i, c){
        int aa, bb;
        scanf("%d%d", &aa, &bb);
        tasks.pb(mp(aa, bb));
    }
    sort(all(tasks), acomp);
    int ans = -1;
    multiset<int> S;
    fr(i, c){
        if((tasks[i].first - a)*ta > t){
            break;
        }
        int cura = tasks[i].first, curb = b + (t - (max(tasks[i].first - a, 0))*ta)/tb;
        S.insert(-tasks[i].second);
        while(!S.empty()){
            int minele = *S.begin();
            if(abs(minele) > curb){
                S.erase(minele);
            }
            else break;
        }
        ans = max(ans, (int)S.size());
    }
    printf("%d\n", ans);
}
