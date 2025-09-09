// LC - 1317 - Easy - Convert Integer to the Sum of Two No-Zero Integers
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1
class Solution{
    bool checkNonZero(int num){
        while(num){
            if(num%10==0) return false;
            num/=10;
        }
        return true;
    }
    public:
    vector<int> getNoZeroIntegers(int n){
        for(int a=1;a<=n-1;a++){
            int b=n-a;
            if(checkNonZero(a) && checkNonZero(b)){
                return {a,b};
            }
        }
        return {-1,-1};
    }
};
// Approach 2
vector<int> getNoZeroIntegers(int n){
    int a=n;
    int b=0;
    int placeValue=1;

    // a+b == n
    while(n>1){
        int take=1;

        if(n%10==1) take=2;

        a=a-take*placeValue;
        b=b+take*placeValue;

        // moving to next digit
        n=(n-take)/10;

        placeValue*=10;
    }
    return {a,b};
}
int main(){
    // Output: [1,1]
    int n=2;
    // Output: [2,9]
    int n2=11;
    return 0;
}