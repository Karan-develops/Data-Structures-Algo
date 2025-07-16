// GFG - Divisible by 13
#include<iostream>
using namespace std;
bool divby13(string &s){
    int ans=0;
    for(char &ch:s){
        ans=(ans*10+(ch-'0'))%13;
    }
    return ans==0;
}
int main(){
    // Output : true
    string s="2911285";
    // Output : false
    string s2="27";
    cout<<divby13(s)<<endl;
    cout<<divby13(s2);
    return 0;
}