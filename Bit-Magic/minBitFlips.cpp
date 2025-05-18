// LC - 2220 - Easy - Minimum Bit Flips to Convert Number
// Tip:- We Have to count number of different bits in both numbers.
#include<iostream>
using namespace std;
int minBitFlips(int start,int goal){
    return __builtin_popcount(start^goal);
}
int main(){
    // Output: 3
    int start=10,goal=7;
    // Output: 3
    int start2=3,goal2=4;
    cout<<minBitFlips(start,goal)<<endl;
    cout<<minBitFlips(start2,goal2);
    return 0;
}