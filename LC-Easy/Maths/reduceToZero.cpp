// LC - 1342 - Easy - Number of Steps to Reduce a Number to Zero
#include<iostream>
using namespace std;
int numberOfSteps(int num) {
    int ans=0;

    while(num){
        if(num&1) num--;
        else num/=2;
        ans++;
    }
    return ans;
}
int main(){
    // Output: 6
    int num=14;
    // Output: 4
    int num2=8;
    // Output: 12
    int num3=123;
    cout<<numberOfSteps(num)<<endl;
    cout<<numberOfSteps(num2)<<endl;
    cout<<numberOfSteps(num3);
    return 0;
}