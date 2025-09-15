// GFG - String stack
#include<iostream>
using namespace std;
bool stringStack(string &pat,string &tar){
    int m=pat.length();
    int n=tar.length();
    
    
    int i=m-1,j=n-1;
    
    while(i>=0 && j>=0){
        if(pat[i]==tar[j]) i--,j--;
        else i-=2;
    }
    
    return j<0;
}
int main(){
    // Output: true
    string pat="geuaek",tar="geek";
    // Output: true
    string pat2="agiffghd",tar2="gfg";
    // Output: false
    string pat3="ufahs",tar3="aus";
    cout<<stringStack(pat,tar)<<endl;
    cout<<stringStack(pat2,tar2)<<endl;
    cout<<stringStack(pat3,tar3);
    return 0;
}