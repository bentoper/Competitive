#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){
    string s; cin >> s;
    int n = s.size();
    int a0 = -1, zf = -1;
    fr(i, n){
        if(s[i] == 'A' && a0 == -1) a0 = i;
        else if(s[i] == 'Z') zf = max(zf, i);
    }
    cout << zf - a0 + 1 << endl;

}
