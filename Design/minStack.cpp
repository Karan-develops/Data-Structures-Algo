#include<iostream>
#include<vector>
using namespace std;
class MinStack{
    vector<pair<int,int>>st;
    public:
    void push(int val) {
        if(st.empty()){
            pair<int,int>p=make_pair(val,val);
            st.push_back(p);
        } else{
            pair<int,int>p=make_pair(val,min(val,st.back().second));
            st.push_back(p);
        }
    }
    void pop(){
        if(st.empty()) return;
        st.pop_back();
    }    
    int top(){
        if(st.empty()) return -1;
        return st.back().first;
    }    
    int getMin(){
        if(st.empty()) return -1;
        return st.back().second;
    }
};
int main(){
    MinStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.top()<<endl;
    cout<<st.getMin();
    return 0;
}