#include "bits/stdc++.h"
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
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    int N, A, B; cin >> N >> A >> B;
    if(A == 1 or B == 1){
        fr(i, N) cout << 1 + i << " ";
        gnl;
        return 0;
    }
     if(A > B){
        int aux = A;
        A = B;
        B = aux;
    }
    int prim = 0;
    while(N%B != 0 && N > 0){
        N -= A;
        prim++;
    }
    if(N < 0){
        cout << -1 << endl;
        return 0;
    }
    int last = 2;
    if(prim){
        int bc = 0; int out = 2;
        while(prim--){
            out = 2 + A*bc;
            fr(i, A - 1){
                cout << out + i << " ";
            }
            cout << 1 + A*bc << " ";
            bc++;
            last = A*bc;
        }
    }
    if(N%B == 0 && N != 0){
        int bc = 0; int out = 2;
        while(N){
            if(last != 2) out = 2 + last + B*bc;
            else out = 2 + B*bc;
            fr(i, B - 1) cout << out + i << " ";
            if(last == 2) cout << 1 + B*bc << " ";
            else cout << last + 1 + B*bc << " "; 
            bc++;
            N -= B;
        }
    }
    gnl;
}
