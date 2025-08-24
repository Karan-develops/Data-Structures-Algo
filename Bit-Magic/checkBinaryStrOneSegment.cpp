// LC - 1784 - Easy - Check if Binary String Has at Most One Segment of Ones
#include<iostream>
using namespace std;
bool checkOnesSegment(string s){
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='0' && s[i+1]=='1') return false;
    }
    return true;
}
int main(){
    // Output: false
    string s="1001";
    // Output: true
    string s2="110";
    cout<<checkOnesSegment(s)<<endl;
    cout<<checkOnesSegment(s2);
    return 0;
}