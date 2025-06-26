// GFG - Game with String
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minValue(string &s,int k){
    vector<int>v(26,0);
    
    for(char &ch:s) v[ch-'a']++;
    
    priority_queue<int>pq;
    
    for(int &i:v) if(i>0) pq.push(i);
    
    while(k--){
        int x=pq.top();
        pq.pop();
        x-=1;
        if(x!=0) pq.push(x);
    }
    
    int ans=0;
    while(!pq.empty()){
        ans+=pq.top()*pq.top();
        pq.pop();
    }
    return ans;
}
int main(){
    // Output: 6
    string s="abbccc";
    int k=2;
    // Output: 2
    string s2="aaab";
    int k2=2;
    cout<<minValue(s,k)<<endl;
    cout<<minValue(s2,k2);
    return 0;
}