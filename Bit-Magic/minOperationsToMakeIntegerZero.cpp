// LC - 2749 - Medium - Minimum Operations to Make the Integer Zero
// 2 Approaches
#include<iostream>
using namespace std;
// Approach 1 - Bit Magic
int makeTheIntegerZero(int num1,int num2){
    int ans=0;

    while(true){
        long long val=(long long)num1-(long long)ans*num2;

        if(val<0) return -1;
        
        if(__builtin_popcountll(val)<=ans && ans<=val){
            return ans;
        }
        ans++;
    }
    return -1;
}
// Approach 2 - Maths
int makeTheIntegerZero2(int num1,int num2){
    for(int t=1;t<=36;t++){
        long long val=(long long)num1-(long long)t*num2;

        if(val<0) return -1;
        
        if(__builtin_popcountll(val)<=t && t<=val){
            return t;
        }
    }
    return -1;
}
int main(){
    // Output: 3
    int num1=3,num2=-2;
    // Output: -1
    int num3=5,num4=7;
    cout<<makeTheIntegerZero(num1,num2)<<endl;
    cout<<makeTheIntegerZero(num3,num4);
    return 0;
}