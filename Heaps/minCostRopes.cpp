// GFG - Minimum Cost of ropes
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCost(vector<int>&arr){
    if(arr.size()==1) return 0;
    
    priority_queue<int,vector<int>,greater<>>pq(begin(arr),end(arr));
    int ans=0;
    
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        
        ans+=(first+second);
        
        pq.push(first+second);
    }
    
    return ans;
}
int main(){
    // Output: 29
    vector<int>arr={4,3,2,6};
    // Output: 62
    vector<int>arr2={4,2,7,6,9};
    // Output: 0
    vector<int>arr3={10};
    cout<<minCost(arr)<<endl;
    cout<<minCost(arr2)<<endl;
    cout<<minCost(arr3);
    return 0;
}