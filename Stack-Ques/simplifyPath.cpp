// LC - 71 - Medium - Simplify Path
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;
// Tokenizing the string on the basis of /
string simplifyPath(string path){
    string token="";
    stringstream ss(path);
    stack<string>st;
    while(getline(ss,token,'/')){
        if(token=="." || token=="") continue;

        if(token!="..") st.push(token);
        else if(!st.empty()) st.pop();
    }
    string ans="";
    while(!st.empty()){
        ans="/"+st.top()+ans;
        st.pop();
    }
    if(ans.length()==0) ans="/"; // returning root
    return ans;
}
int main(){
    // Output: "/home"
    string path="/home/";
    // Output: "/home/foo"
    string path2="/home//foo/";
    // Output: "/home/user/Pictures"
    string path3="/home/user/Documents/../Pictures";
    // Output: "/"
    string path4= "/../";
    // Output: "/.../b/d"
    string path5= "/.../a/../b/c/../d/./";
    cout<<simplifyPath(path)<<endl;
    cout<<simplifyPath(path2)<<endl;
    cout<<simplifyPath(path3)<<endl;
    cout<<simplifyPath(path4)<<endl;
    cout<<simplifyPath(path5);
    return 0;
}