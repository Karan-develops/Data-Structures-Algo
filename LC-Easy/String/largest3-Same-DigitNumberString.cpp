// LC - 2264 - Easy - Largest 3-Same-Digit Number in String
#include<iostream>
using namespace std;
string largestGoodInteger(string num){
    int n=num.length();
    string ans;

    for(int i=1;i<n-1;i++){
        if(num[i]==num[i-1] && num[i]==num[i+1]){
            ans=max(ans,string(3,num[i]));
        }
    }
    return ans;
}
int main(){
    // Output: "777"
    string num="6777133339";
    // Output: "000"
    string num2="2300019";
    // Output: ""
    string num3="42352338";
    cout<<largestGoodInteger(num)<<endl;
    cout<<largestGoodInteger(num2)<<endl;
    cout<<largestGoodInteger(num3);
    return 0;
}