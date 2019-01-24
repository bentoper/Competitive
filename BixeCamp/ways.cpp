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
#define rvr(x) int x; scanf("%d", &x);
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

ll aux[1000000], n, summation[1000000], acc;
ll counter = 0, tot;
vector<ll> ltr, rtl;

int mysort(pair<ll, int> a, pair<ll, int> b){
	if(a.first > b.first) return 0;
	if(a.first == b.first && a.snd > b.snd) return 0;
	return 1;
}


int main(){
	scanf("%lld", &n);
	ltr.pb(0);
	rtl.pb(0);
	frr(i, n){
		scanf("%lld", &aux[i]);
		ltr.pb(ltr[i-1]+aux[i]);
	}
	tot = ltr[n];
	if(tot%3 != 0){
		printf("0\n"); return 0;
	}
	ll srch = tot/3;
	//dbg(srch);
	for(int i = n; i > 0; i--){
		rtl.pb(rtl[n - i]+aux[i]);
		//dbg(rtl[n-i+1]);
	}
	frr(i, n-1){
		if(rtl[i] == srch) acc++;
	}
	summation[n] = 0;
	summation[0] = acc;
	frr(i, n){
		summation[i] = summation[i-1] - (rtl[n - i + 1]==srch?1:0);
		//if(summation[i] == 0) olar;	
	}

	frr(i, n-1){
		if(ltr[i] == srch) counter += summation[i];
	}
	printf("%lld\n", counter);
}
