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
const int N = 1001;

int arr[N];

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        ms(arr, 0);
        int n, k; cin >> n >> k;
        vector<vi> sets(k);
        fr(i, k){
            int c; cin >> c;
            fr(j, c){
                int a; cin >> a;
                sets[i].pb(a);
                arr[a] = i+1;
            }
        }
        cout << "? " << n << " ";
        frr(i, n) cout << i << " ";
        cout << endl;
        cout.flush();
        int plc; cin >> plc;
        int l = 1, r = n;
        while(r > l){
            int mid = (l + r)/2;
            cout << "? " << mid - l + 1 << " ";
            for(int i = l; i <= mid; i++){
                cout << i << " ";
            }
            cout << endl;
            cout.flush();
            int ret; cin >> ret;
            if(ret == plc) r = mid;
            else l = mid + 1;
        }
        if(arr[l] == 0){
            cout << "! ";
            fr(i, k){
                cout << plc << " ";
            }
            cout << endl;
            cout.flush();
        }
        else{
            cout << "? " << n - sets[arr[l]-1].size() << " ";
            frr(i, n){
                if(arr[i] == arr[l]) continue;
                cout << i << " ";                
            }
            cout << endl;
            cout.flush();
            int ret; cin >> ret;
            cout << "! ";
            fr(i, k){
                if(i == arr[l] - 1) cout << ret << " ";
                else cout << plc << " ";
            }
            cout << endl;
            cout.flush();
        }
        string lixo; cin >> lixo;
        cout.flush();
    }
}
