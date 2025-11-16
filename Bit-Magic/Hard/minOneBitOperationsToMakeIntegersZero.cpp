// LC - 1611 - HARD - Minimum One Bit Operations to Make Integers Zero
#include<iostream>
using namespace std;
int minimumOneBitOperations(int n){
    int ans=0;

    while(n){
        ans^=n;
        n>>=1;
    }

    return ans;
}
int main(){
    // Output: 2
    int n=3;
    // Output: 4
    int n2=6;
    cout<<minimumOneBitOperations(n)<<endl;
    cout<<minimumOneBitOperations(n2);
    return 0;
}