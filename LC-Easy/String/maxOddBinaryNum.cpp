// LC - 2864 - Easy - Maximum Odd Binary Number
#include<iostream>
#include<algorithm>
using namespace std;
string maximumOddBinaryNumber(string s){
    int ones=count(begin(s),end(s),'1');
    ones--;

    for(int i=0;i<s.length();i++){
        if(i==s.length()-1) s[i]='1';
        else if(ones>0) s[i]='1';
        else s[i]='0';

        ones--;
    }
    return s;
}
int main(){
    // Output: "001"
    string s="010";
    // Output: "1001"
    string s2="0101";
    cout<<maximumOddBinaryNumber(s)<<endl;
    cout<<maximumOddBinaryNumber(s2);
    return 0;
}