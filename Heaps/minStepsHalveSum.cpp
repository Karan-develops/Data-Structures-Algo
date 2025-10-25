// GFG - Medium - Minimum Steps to Halve Sum
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minOperations(vector<int>&arr){
    double total=0;
    
    priority_queue<double>pq;
    
    for(int &i:arr){
        pq.push(i*1.0);
        total+=(i*1.0);
    }
    
    double half=total/2.0;
    int ans=0;
    
    while(total>half){
        double top=pq.top();
        pq.pop();
        
        total-=top/2.0;
        pq.push(top/2.0);
        
        ans++;
    }
    
    return ans;
}
int main(){
    // Output: 3
    vector<int>arr={8,6,2};
    // Output: 2
    vector<int>arr2={9,1,2};
    cout<<minOperations(arr)<<endl;
    cout<<minOperations(arr2);
    return 0;
}