#include <bits/stdc++.h>
using namespace std;

int problems[15], n, l, r, x, c;
int subsets(int maximo, int minimo, int sum, int item){
    if(item == n){
        int diff = maximo - minimo;
        if(sum < l or sum > r or diff < x){
            return 0;
        }
        c++;
        return 0;
    }
    if(item != -1){
        int newmax;
        int newmin;
        int newsum;
        newmax = max(maximo, problems[item]);
        newmin = min(minimo, problems[item]);
        newsum = sum + problems[item];
        int diff = maximo - minimo;
        subsets(newmax, newmin, newsum, item+1);
        subsets(maximo, minimo, sum, item+1);
    }
    else{
        subsets(maximo, minimo, sum, item+1);
    }
    return c;

}


int main(){
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++){
        cin >> problems[i];
    }
    cout << subsets(0, 1000000, 0, -1) << endl;
}
