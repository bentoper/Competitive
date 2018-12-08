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

int N;

pii consultations[10000];

int mysort(pii a, pii b){
	return(a.snd < b.snd);
}

int main(){
	scanf("%d", &N);
	fr(i, N){
		rvr(aux1) rvr(aux2)
		consultations[i] = {aux1, aux2};
	}
	sort(consultations, consultations+N, mysort);
	int last = 0, count = 0;
	fr(i, N){
		if(consultations[i].first >= last){
			count++; last = consultations[i].snd;
		}
	}
	printf("%d\n", count);
}
