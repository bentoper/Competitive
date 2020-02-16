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
const int N = 1000;

int id[N], t[N], l[N], h[N];

bool mycomp(int a, int b){
    return t[a] < t[b];
}

int main(){ 
    rvr(q);
    while(q--){
        int n, m; scanf("%d%d", &n, &m);
        fr(i, n){
            scanf("%d%d%d", &t[i], &l[i], &h[i]);
            id[i] = i;
        }
        sort(id, id+n, mycomp);
        pii range, temp;
        bool deu = false;
        int time = 0;
        int cur = id[0];
        if(l[cur] > m){
            if(m + t[cur] < l[cur]) goto END;
            else range = mp(l[cur], h[cur]);

        }
        else if(h[cur] < m){
            if(m - t[cur] > h[cur]) goto END;
            else range = mp(l[cur], h[cur]);
        }
        else range = mp(l[cur], h[cur]);
        deu = true;
        temp = mp(max(l[cur], m - t[cur]), min(h[cur], m + t[cur]));
        time = t[cur];
        for(int i = 1; i < n; i++){
            cur = id[i];
            int pp = t[cur];
            t[cur] = t[cur] - time;
            time = max(time, pp);
            if(temp.first - t[cur] >  h[cur] || temp.second + t[cur] < l[cur]){
                deu = false;
                break;
            }
            temp.first = max(l[cur], temp.first - t[cur]);
            temp.second = min(h[cur], temp.second + t[cur]);
        }
        END:
        if(!deu){
            printf("NO\n");
        }
        else printf("YES\n");
    }     
}
