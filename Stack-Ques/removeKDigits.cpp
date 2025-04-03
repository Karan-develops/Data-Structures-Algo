// LC - 402 - Medium - Remove K Digits
#include<iostream>
#include<vector>
using namespace std;
string removeKdigits(string num,int k){
    if(k==num.length()) return "0";
    string ans="";
    for(char &ch:num){
        while(ans.length()>0 && k>0 && ans.back()>ch){
            ans.pop_back();
            k--;
        }
        if(ans.length()>0 || ch!='0') ans.push_back(ch);
    }
    while(ans.length()>0 && k>0){
        ans.pop_back();
        k--;
    }
    if(ans=="") return "0";
    return ans;
}
int main(){
    // Output: "1219"
    string num="1432219";
    int k=3;
    // Output: "200"
    string num2="10200";
    int k2=1;
    // Output: "0"
    string num3="10";
    int k3=2;
    cout<<removeKdigits(num,k)<<endl;
    cout<<removeKdigits(num2,k2)<<endl;
    cout<<removeKdigits(num3,k3);
    return 0;
}