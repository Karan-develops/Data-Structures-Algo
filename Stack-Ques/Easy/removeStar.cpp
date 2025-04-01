// LC - 2390 - Medium - Removing Stars From a String
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
string removeStars(string s) {
    string ans="";
    for(char &ch:s){
        if(ch!='*') ans.push_back(ch);
        else ans.pop_back();
    }
    return ans;
}
int main(){
    // Output: "lecoe"
    string s="leet**cod*e";
    // Output: ""
    string s2="erase*****";
    cout<<removeStars(s)<<endl;
    cout<<removeStars(s2);
    return 0;
}