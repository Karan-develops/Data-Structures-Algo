// GFG - Maximum Sum Combination
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
vector<int> topKSumPairs(vector<int>&a,vector<int>&b,int k){
    int n=a.size();
    vector<int>ans;
    
    sort(rbegin(a),rend(a));
    sort(rbegin(b),rend(b));
    
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>st;
    
    pq.push({a[0]+b[0],{0,0}});
    st.insert({0,0});
    
    while(ans.size()<k){
        auto top=pq.top();
        pq.pop();
        
        int sum=top.first;
        int i=top.second.first;
        int j=top.second.second;
        
        ans.push_back(sum);
        
        if(j+1<n && !st.count({i,j+1})){
            pq.push({a[i]+b[j+1],{i,j+1}});
            st.insert({i,j+1});
        }
        
        if(i+1<n && !st.count({i+1,j})){
            pq.push({a[i+1]+b[j],{i+1,j}});
            st.insert({i+1,j});
        }
    }
    return ans;
}
int main(){
    // Output: [7, 6]
    vector<int>a={3,2},b={1,4};
    int k=2;
    // Output: [10, 9, 9]
    vector<int>a2={1,4,2,3},b2={2,5,1,6};
    int k=3;
    return 0;
}