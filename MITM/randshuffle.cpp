//https://community.topcoder.com/stat?c=problem_statement&pm=7833&rd=10803
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
#define gnl printf("\n");
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

map<vi, double> st;
int n;

double ans = 0.;

void topdown(vi s, double prob, int step){
    if(step == n/2 + n%2){
        st[s] += prob;        
        return;
    }
    fr(i, n){
        swap(s[i], s[step]);
        topdown(s, prob*(1./(double)n), step + 1);
        swap(s[i], s[step]);
    }
}

void bottomup(vi s, double prob, int step){
    if(step == n/2){
        ans = ans + prob*st[s];
        return;
    }
    fr(i, n){
        swap(s[i], s[n - step - 1]);
        bottomup(s, prob*(1./(double)n), step + 1);
        swap(s[i], s[n - step - 1]);
    }
}



class RandomShuffle{
    public:

    double probability(vector<int> outputArray){
        n = outputArray.size();
        vi base(n);
        frr(i, n){
            base[i-1] = i;
        }
        topdown(base, 1., 0);
        bottomup(outputArray, 1., 0);
        return ans;
    }
};
