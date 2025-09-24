// LC - 1381 - Medium - Design a Stack With Increment Operation
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - O(k) increment function
class Design{
    int MAX_SIZE;
    vector<int>st;
    public:
    Design(int maxSize){
        MAX_SIZE=maxSize;
    }
    void push(int x){
        if(st.size()>=MAX_SIZE) return;

        st.push_back(x);
    }
    int pop(){
        if(st.empty()) return -1;

        int top=st.back();
        st.pop_back();

        return top;
    }
    void increment(int k,int val){
        for(int i=0;i<k && i<st.size();i++){
            st[i]+=val;
        }
    }
};
// Approach 2 - O(1) Every Function
class Stack{
    public:
    int n;
    vector<int>st;
    vector<int>increments;
    Stack(int maxSize){
        n=maxSize;
    }
    void push(int x){
        if(st.size()<n){
            st.push_back(x);
            increments.push_back(0);
        }
    }
    int pop(){
        if(st.empty()) return -1;

        int top=st.back();
        int incVal=increments.back();

        st.pop_back();
        increments.pop_back();

        if(increments.size()>0){
            increments.back()+=incVal;
        }

        return top+incVal;
    }
    void increment(int k,int val){
        int idx=min((int)st.size(),k)-1;

        if(idx>=0){
            increments[idx]+=val;
        }
    }
};