// LC - 3019 - Easy - Number of Changing Keys
#include<iostream>
using namespace std;
int countKeyChanges(string s) {
    int ans=0;
    for(int i=0;i<s.length()-1;i++){
        int x=islower(s[i])?s[i]-'a':s[i]-'A';
        int y=islower(s[i+1])?s[i+1]-'a':s[i+1]-'A';
        if(x!=y) ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    string s="aAbBcC";
    // Output: 0
    string s2="AaAaAaaA";
    cout<<countKeyChanges(s)<<endl;
    cout<<countKeyChanges(s2);
    return 0;
}