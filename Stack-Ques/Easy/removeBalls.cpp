// GFG - Remove the balls
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int findLength(vector<int>&color,vector<int>&radius){
    int n=color.size();
    stack<pair<int,int>>st;
    
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push({color[i],radius[i]});
            continue;
        }
        if(st.top().first==color[i] && st.top().second==radius[i]){
            st.pop();
        } else{
            st.push({color[i],radius[i]});
        }
    }
    return st.size();
}
int main(){
    // Output: 3
    vector<int>color={2,3,5},radius={3,3,5};
    // Output: 1
    vector<int>color2={2,2,5},radius2={3,3,5};
    cout<<findLength(color,radius)<<endl;
    cout<<findLength(color2,radius2);
    return 0;
}