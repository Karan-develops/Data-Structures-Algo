// LC - 258 - Easy - Add Digits
// Follow Up - O(1) Time
#include<iostream>
using namespace std;
int addDigits(int num){
    if(num>=0 && num<=9) return num;
    
    int sum=0;

    while(num){
        int digit=num%10;
        sum+=digit;
        num/=10;
    }
    return addDigits(sum);
}
int followUp(int num){
    if(num==0) return 0;

    if(num%9==0) return 9;

    return num%9;
}
int main(){
    // Output: 2
    int num=38;
    // Output: 0
    int num2=0;
    cout<<addDigits(num)<<endl;
    cout<<addDigits(num2);
    return 0;
}