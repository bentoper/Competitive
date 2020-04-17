//https://community.topcoder.com/stat?c=problem_statement&pm=6742&rd=10763
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

int n;

ll digsum(vi a){
    int nn = a.size() - 1;
    ll plc = 0;
    for(; nn >= 0; nn--){
        plc += a[nn];
    }
    return plc;
}

ll diff(vi bg, vi sml){
    int nn = bg.size() - 1;
    ll plc = 0;
    for(; nn >= 0; nn--){
        plc *= 10ll;
        plc += bg[nn] - sml[nn];
    }
    return plc;
}

ll stp(vi st){
    ll csum = 0;
    ll ans = 0;
    int nnn;
    vi plc;
    fr(i, st.size()){
        csum += st[i];
        plc.pb(st[i]);
    }
    nnn = st.size();
    while(1){
        ans += csum;
        plc[0] += 1;
        int pos = 0;
        while(plc[pos] == 10){
            plc[pos] = 0;
            csum -= 9;
            pos++;
            if(pos == nnn){
                return ans;
            }
            plc[pos] += 1;
        }
        csum += 1;
    }
}

ll solve(vi st, vi ed){
    ll csum = 0;
    ll ans = 0;
    int nnn;
    vi plc;
    int ss = diff(ed, st);
    nnn = st.size();
    fr(i, nnn){
        csum += st[i];
        plc.pb(st[i]);
    }
    fr(i, ss+1){
        //pv(plc, plc.size());
        ans += csum;
        plc[0] += 1;
        int pos = 0;
        while(plc[pos] == 10){
            plc[pos] = 0;
            csum -= 9;
            pos++;
            if(pos == nnn){
                return ans;
            }
            plc[pos] += 1;
        }
        csum += 1;
    }
    return ans;
}

class SumThemAll{

    public:

    long long getSum(int lowerBound, int upperBound){
        vi aa, bb;
        ll ans = 0;
        if(lowerBound == upperBound){
            ll aaaaa = 0;
            while(lowerBound > 0){
                aaaaa += lowerBound%10;
                lowerBound /= 10;
            }
            return aaaaa;
        }

        while(lowerBound != 0){
            aa.pb(lowerBound%10);
            lowerBound /= 10;
        }
        while(upperBound != 0){
            bb.pb(upperBound%10);
            upperBound /= 10;
        }
        
        n = bb.size();
        vi la(n/2 + n%2), ra(n/2), lb(n/2 + n%2), rb(n/2);
        fr(i, n/2 + n%2){
            if(aa.size() > i){
                la[i] = aa[i];
            }
            else la[i] = 0;
            lb[i] = bb[i];
        }
        for(int i = n/2 + n%2, j = 0; i < n; i++, j++){
            if(aa.size() > i){
                ra[j] = aa[i];
            }
            else ra[j] = 0;
            rb[j] = bb[i];
        }

        vi lx(n/2 + n%2, 0);
        vi lxx(n/2 + n%2, 9);

        ll dd = diff(rb, ra);
        if(dd == 0){
            ans = solve(la, lb) + digsum(ra)*(diff(lb, la) + 1);
            return ans;
        }

        int sz = diff(lxx, lx) + 1, cst = stp(lx), ds = digsum(ra); 
        int pos = 0;
        ans += (stp(la) + (diff(lxx, la) + 1ll)*ds);
        ra[pos]++;
        dd--;
        while(ra[pos] == 10){
            ra[pos] = 0;
            ds -= 9;
            pos++;
            if(pos >= ra.size()) break;
            ra[pos]++;
        }
        ds++;
        while(dd > 0){
            ans += ds*sz;
            ans += cst;
            pos = 0;
            ra[pos]++;
            while(ra[pos] == 10){
                ra[pos] = 0;
                ds -= 9;
                pos++;
                ra[pos]++;
            }
            ds++;
            dd--;
        }
        ans += ds*(diff(lb, lx) + 1ll) + solve(lx, lb);
        return ans;
    }
};
