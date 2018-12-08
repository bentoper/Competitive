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

int firstcall = 1;

ll m, n;

ll recursum(ll m){
	if(m == 1) return 0;
	if(m == 2) return 1;
	ll aux = m;
	if(m%2 == 0) aux = m-1;
	m/=2;
	m*=aux;
	return m;
}

int main(){
	scanf("%lld%lld", &n, &m);
	if(n == m){
		printf("0 0\n");
		return 0;
	}
	ll inteam = n - m + 1;
	ll maximal = recursum(inteam);
	ll aux = n%m;
	ll aux2 = n/m;
	ll minimal = m*recursum(aux2) + aux*aux2;
	/*if(maximal%2){
		aux = maximal;
		if(aux != 1) aux/=2;
		maximal*=aux;
	}
	else{
		aux = maximal - 1;
		if(aux != 1) aux/=2;
		maximal*=aux;
	}
	ll left = n/m;
	if(left%2){
		ll aux = left;
		if(aux != 1) aux/=2;
		left*=aux;
	}
	else{
		ll aux = left-1;
		if(aux != 1) aux/=2;
		left*=aux;
	}
	ll mod = n%m;
	ll quo = n/m;
	ll minimal = m*left + mod*quo;*/
	printf("%lld %lld\n", minimal, maximal);
}
