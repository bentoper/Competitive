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

int mapa[100001];

ll mergesort(vector<int> &v){
	
	int tam=v.size();
	if(tam==1)	return 0;
	
	vector<int> v1,v2;
	for(int i=0; i< tam/2; i++)	v1.pb(v[i]);
	for(int i = tam/2; i<tam; i++)		v2.pb(v[i]);
	
	ll inv=0;
	inv+=mergesort(v1);
	inv+=mergesort(v2);
	
	v1.pb(INF);
	v2.pb(INF);
	
	int ini1=0 , ini2=0, s=v1.size();
	
	for(int i=0;i<tam;i++){
		
		if(v1[ini1]<=v2[ini2]){
			v[i]=v1[ini1];
			ini1++;
		}

		else{
			v[i]=v2[ini2];
			ini2++;
			inv+=s-1-ini1;
		}
	}

	return inv;

}

int main(){
	rvr(t);
	while(t--){
		rvr(n); vector<int> vetor(n+1, 0);
		frr(i, n){
			rvr(aux);
			mapa[aux] = i;
		}
		frr(i, n){
			rvr(aux);
			vetor[i] = mapa[aux];
		}
		printf("%lld\n", mergesort(vetor));
	}

}
