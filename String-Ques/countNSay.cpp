// LC - 38 - Medium - Count and Say
#include<iostream>
using namespace std;
string countAndSay(int n){
    if(n==1) return "1";
    string say=countAndSay(n-1);

    string ans="";
    for(int i=0;i<say.length();i++){
        char ch=say[i];
        int count=1;
        while(i<say.length()-1 && say[i]==say[i+1]){
            count++;
            i++;
        }
        ans+=to_string(count)+string(1,ch);
    }
    return ans;
}
int main(){
    // Output: "1211"
    int n=4;
    // Output: "1"
    int n2=1;
    cout<<countAndSay(n)<<endl;
    cout<<countAndSay(n2);
    return 0;
}