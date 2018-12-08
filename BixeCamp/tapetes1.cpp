#include <iostream>
using namespace std;

int main(){
    int s, n;
    cin >> s >> n;
    s = s - (n-1);
    cout << (s*s) + (n-1);
}
