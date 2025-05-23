// LC - 3362 - Medium - Zero Array Transformation III
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int maxRemoval(vector<int>&nums,vector<vector<int>>&queries){
    int n=nums.size();
    int usedQueries=0;

    sort(begin(queries),end(queries));

    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<>>minHeap;

    int j=0;
    for(int i=0;i<n;i++){
        while(j<queries.size() && queries[j][0]==i){
            maxHeap.push(queries[j][1]);
            j++;
        }

        nums[i]-=minHeap.size();

        while(nums[i]>0 && !maxHeap.empty() && maxHeap.top()>=i){
            int top=maxHeap.top(); maxHeap.pop();
            minHeap.push(top);
            usedQueries++;
            nums[i]--;
        }
        
        if(nums[i]>0) return -1;

        while(!minHeap.empty() && minHeap.top()<=i){
            minHeap.pop();
        }
    }
    return queries.size()-usedQueries;
}
int main(){
    // Output: 1
    vector<int>nums={2,0,2};
    vector<vector<int>>queries={{0,2},{0,2},{1,1}};
    // Output: 2
    vector<int>nums2={1,1,1,1};
    vector<vector<int>>queries2={{1,3},{0,2},{1,3},{1,2}};
    // Output: -1
    vector<int>nums3={1,2,3,4};
    vector<vector<int>>queries3={{0,3}};
    cout<<maxRemoval(nums,queries)<<endl;
    cout<<maxRemoval(nums2,queries2)<<endl;
    cout<<maxRemoval(nums3,queries3);
    return 0;
}