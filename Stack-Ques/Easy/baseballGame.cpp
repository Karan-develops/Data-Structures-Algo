// LC - 682 - Easy - Baseball Game
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int calPoints(vector<string>&operations){
    int ans=0;
    stack<int>st;
    for(string s:operations){
        if(s=="+"){
            int x=st.top(); st.pop();
            int y=st.top();
            st.push(x);
            st.push(x+y);
        } else if(s=="D"){
            int x=st.top();
            st.push(x*2);
        } else if(s=="C"){
            st.pop();
        } else{
            st.push(stoi(s));
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    // Output: 30
    vector<string>ops={"5","2","C","D","+"};
    // Output: 27
    vector<string>ops2={"5","-2","4","C","D","9","+","+"};
    // Output: 0
    vector<string>ops3={"1","C"};
    cout<<calPoints(ops)<<endl;
    cout<<calPoints(ops2)<<endl;
    cout<<calPoints(ops3);
    return 0;
}