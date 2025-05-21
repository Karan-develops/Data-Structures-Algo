// LC - 3370 - Easy - Smallest Number With All Set Bits
// Approach 1 - Using String
#include<iostream>
#include<math.h>
using namespace std;
int smallestNumber(int n){
    int ans=0;
    string s;
    for(int i=31;i>=0;i--){
        int temp=(1<<i);
        if((temp&n)>0){
            s=string(i+1,'1');
            break;
        }
    }
    ans=stoi(s,nullptr,2);
    return ans;
}
// Approach 2 - Changing input
int smallestNumber2(int n){
    bool flag=false;
    for(int i=31;i>=0;i--){
        int temp=(1<<i);
        if(flag) n|=temp;

        if((temp&n)>0) flag=true;
    }
    return n;
}
// Approach 3 - Using Power of 2
int smallestNumber3(int n){
    return pow(2,ceil(log2(n+1)))-1;
}
// Approach 4 - Using Inbuilt Library
int smallestNumber4(int n){
    return (1<<(32-__builtin_clz(n)))-1;
}
int main(){
    // Output: 7
    int n=5;
    // Output: 15
    int n2=10;
    // Output: 3
    int n3=3;
    cout<<smallestNumber(n)<<endl;
    cout<<smallestNumber(n2)<<endl;
    cout<<smallestNumber(n3);
    return 0;
}