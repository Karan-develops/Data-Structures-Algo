// LC - 258 - Easy - Add Digits
// Add Until the digit becomes 1-Digit
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
int main(){
    // Output: 2
    int num=38;
    // Output: 0
    int num2=0;
    cout<<addDigits(num)<<endl;
    cout<<addDigits(num2);
    return 0;
}