// LC - 394 - Medium - Decode String
#include<iostream>
#include<stack>
using namespace std;
class Stack{
    bool isDigit(string &ch){
        return (ch=="0" || ch=="1" || ch=="2" || ch=="3" || ch=="4" || ch=="5"
          || ch=="6" || ch=="7" || ch=="8" || ch=="9");
    }
    public:
    string decodeString(string s){
        stack<string>st;
        
        for(char &ch:s){
            if(ch!=']'){
                st.push(string(1,ch));
                continue;
            }
            
            string temp="";
            while(!st.empty() && st.top()!="["){
                temp=st.top()+temp;
                st.pop();
            }
            
            if(!st.empty()){
                st.pop();
            }
            
            string num="";
            while(!st.empty() && isDigit(st.top())){
                num=st.top()+num;
                st.pop();
            }
            
            string add="";
            int times=stoi(num);
            while(times--){
                add+=temp;
            }

            st.push(add);
        }
        string ans="";

        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
int main(){
    // Output: "aaabcbc"
    string s="3[a]2[bc]";
    // Output: "accaccacc"
    string s2="3[a2[c]]";
    // Output: "abcabccdcdcdef"
    string s3="2[abc]3[cd]ef";
    
    Stack sol;
    cout<<sol.decodeString(s)<<endl;
    cout<<sol.decodeString(s2)<<endl;
    cout<<sol.decodeString(s3);
    return 0;
}