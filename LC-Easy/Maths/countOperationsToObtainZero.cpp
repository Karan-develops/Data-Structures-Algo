// LC - 2169 - Easy - Count Operations to Obtain Zero
#include<iostream>
using namespace std;
int countOperations(int num1,int num2){
    int ans=0;

    while(num1!=0 && num2!=0){
        if(num1>num2) num1-=num2;
        else num2-=num1;
        ans++;
    }

    return ans;
}
int main(){
    // Output: 3
    int num1=2,num2=3;
    // Output: 1
    int num3=10,num4=10;
    cout<<countOperations(num1,num2)<<endl;
    cout<<countOperations(num3,num4);
    return 0;
}