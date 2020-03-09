#include <bits/stdc++.h> 
using namespace std;
const int SEED = 1;

uniform_int_distribution<> dist(0, 6);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//vector<int> plc(100);
//suffle(plc.begin(), plc.end(), rng);

int main(){
    int a = 1;
    int zero_to_six = uniform_int_distribution<int>(0, 6)(rng);
}