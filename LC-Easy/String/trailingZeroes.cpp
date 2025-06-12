// LC - 2710 - Easy - Remove Trailing Zeros From a String
#include<iostream>
using namespace std;
string removeTrailingZeros(string num) {
    string ans;
    int n=num.length();

    for(int i=n-1;i>=0;i--){
        if(num[i]!='0') break;
        num[i]='*';
    }
    
    for(char &ch:num){
        if(ch=='*') return ans;
        ans+=ch;
    }
    return ans;
}
int main(){
    // Output: "512301"
    string num="51230100";
    // Output: "123"
    string num2="123";
    cout<<removeTrailingZeros(num)<<endl;
    cout<<removeTrailingZeros(num2);
    return 0;
}