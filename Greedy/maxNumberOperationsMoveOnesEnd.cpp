// LC - 3228 - Medium - Maximum Number of Operations to Move Ones to the End
#include<iostream>
#include<vector>
using namespace std;
int maxOperations(string s){
    int ones=0,ans=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='1') ones++;
        else if((i>0) && s[i-1]=='1'){
            ans+=ones;
        }
    }
    return ans;
}
int main(){
    // Output: 4
    string s="1001101";
    // Output: 0
    string s2="00111";
    cout<<maxOperations(s)<<endl;
    cout<<maxOperations(s2);
    return 0;
}