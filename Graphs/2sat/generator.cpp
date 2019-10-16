#include <bits/stdc++.h>
using namespace std;

const long long int RETO = 1e17;
int main(){

    printf("100000\n");
    for(long long int i = 0; i < 100000; i++) {
        printf("%lld %lld 1 -1\n", RETO + i%10000, RETO + (i + 2)%10000);
    }
    
}