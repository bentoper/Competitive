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

map<string, bool> m, av;
vector<string> vec;

int cc[2];

string inv(string a){
    int sz = a.size();
    fr(i, sz/2){
        swap(a[i], a[sz - i - 1]);
    }
    return a;
}

int main(){
    int T; cin >> T;
    while(T--){
        m.clear();
        vec.clear();
        ms(cc, 0);
        int n; cin >> n;
        bool achou = false, zerro = false, onee = false;;
        fr(i, n){
            string s; cin >> s;
            m[s] = true;
            vec.pb(s);
            if(s[0] != s[s.size() - 1]){
                achou = true;
            }
            else if(s[0] == '0') zerro = true;
            else onee = true;
        }
        if(!achou && onee == zerro){
            cout << ("-1\n");
            continue;
        }
        else if(!achou){
            cout << ("0\n");
            continue;
        }
        av.clear();
        fr(i, n){
            string vaca = inv(vec[i]);
            if(m[vaca]) continue;
            else if(vaca[0] == vaca[vaca.size() - 1]) continue;
            cc[vec[i][0] - '0']++;
            av[vec[i]] = true;
        }
        int type = 0, k = 0;
        int ss = av.size();
        int mid = (ss + 1)/2;
        if(zerro || onee){
            if(abs(cc[0] - cc[1]) > 1){
                if(cc[0] < cc[1]){
                    type = 1;
                    k = cc[1] - mid;  
                }
                else k = cc[0] - mid;
            }
        }
        else{
            if(cc[0] > mid){
                k = cc[0] - mid;
            }
            else if(cc[1] > mid){
                type = 1;
                k = cc[1] - mid;
            }
        }
        cout << k << endl;
        if(k == 0) continue;
        fr(i, n){
            if(av[vec[i]]){
                if(type && vec[i][0] == '1'){
                    k--;
                    cout << i+1 << " \n"[k == 0];
                }
                else if(!type && vec[i][0] == '0'){
                    k--;
                    cout << i+1 << " \n"[k == 0];
                }
            }
            if(k == 0) break;
        }
    }
}
