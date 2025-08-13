// LC - 326 - Easy - Power of Three
// 4 Approaches
#include<iostream>
#include<math.h>
using namespace std;
// Approach 1 - Iteratively
bool isPowerOfThreeIterative(int n){
    if(n<=0) return false;
        
    while(n%3==0){
        n/=3;
    }
    return n==1;  
}
// Approach 2 - Recursive
bool isPowerOfThreeRecursive(int n){
    if(n<=0) return false;
    else if(n==1) return true;

    return n%3==0 && isPowerOfThreeRecursive(n/3);  
}
// Approach 3 - Maths ( Using log )
bool isPowerOfThreeLog(int n){
    if(n<=0) return false;

    double logValue=log10(n)/log10(3);

    // Check if logValue is an integer
    return logValue==(int)logValue;
}
// Approach 4 - Checking Largest power of 3 in integer
bool isPowerOfThree(int n){
    // NOTE : 3^19 = 1162261467
    return n>0 && 1162261467%n==0;
}
int main(){
    // Output: true
    int n=27;
    // Output: false
    int n2=0;
    // Output: false
    int n3=-1;
    cout<<isPowerOfThree(n)<<endl;
    cout<<isPowerOfThree(n2)<<endl;
    cout<<isPowerOfThree(n3);
    return 0;
}