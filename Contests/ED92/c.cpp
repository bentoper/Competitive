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

    int main(){
        int t; cin >> t;
        while(t--){
            vi pos[10];
            string s; cin >> s;
            int n = s.size();
            fr(i, n){
                pos[s[i]-'0'].pb(i);
            }
            int ans = -1;
            fr(i, 10) ans = max(ans, (int)pos[i].size());
            fr(i, 10){
                if(pos[i].size() == 0) continue; 
                fr(j, 10){
                    if(i == j) continue;
                    if(pos[j].size() == 0) continue;
                    int ni = pos[i].size(), nj = pos[j].size();
                    int md = 0, curi = 0, curj = 0, last = -1;
                    int plc = 0;
                    while(curi < ni && curj < nj){
                        while(!md && curi < ni && pos[i][curi] < last) curi++;
                        if(!md && curi < ni){
                            last = pos[i][curi];
                            plc++;
                            md ^=1;
                            continue;
                        }
                        while(md && curj < nj && pos[j][curj] < last) curj++;
                        if(md && curj < nj){
                            last = pos[j][curj];
                            md ^=1;
                            plc++;
                            continue;
                        }
                    }
                    ans = max(ans, (plc/2)*2);
                }
            }
            printf("%d\n", n - ans);
        }
    }
