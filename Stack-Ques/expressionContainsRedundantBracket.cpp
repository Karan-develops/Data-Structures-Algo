// GFG - Medium - Expression contains redundant bracket or not
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool checkRedundancy(string &s){
    int lastOpen=-1e9,lastClose=1e9;
    stack<int>st;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            if((lastOpen-st.top()==1 && i-lastClose==1) 
                || (i-st.top()==2)) return 1;
            
            lastOpen=st.top();
            st.pop();
            lastClose=i;
        }
    }
    
    return 0;
}
int main(){
    // Output: true
    string s="((a+b))";
    // Output: true
    string s2="(a+(b)/c)";
    // Output: false
    string s3="(a+b+(c+d))";
    cout<<checkRedundancy(s)<<endl;
    cout<<checkRedundancy(s2)<<endl;
    cout<<checkRedundancy(s3);
    return 0;
}