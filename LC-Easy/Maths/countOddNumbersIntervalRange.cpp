// LC - 1523 - Easy - Count Odd Numbers in an Interval Range
#include<iostream>
using namespace std;
int countOdds(int low,int high){
    int diff=high-low;
    
    int ans=diff/2;

    if((low&1) || (high&1)) ans++;

    return ans;
}
int main(){
    // Output: 3
    int low=3,high=7;
    // Output: 1
    int low2=8,high2=10;
    cout<<countOdds(low,high)<<endl;
    cout<<countOdds(low2,high2);
    return 0;
}