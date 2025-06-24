// LC - 2200 - Easy - Find All K-Distant Indices in an Array
#include<iostream>
#include<vector>
using namespace std;
vector<int> findKDistantIndices(vector<int>&nums,int key,int k){
    int n=nums.size();
    vector<int>ans;

    for(int j=0;j<n;j++){
        if(nums[j]==key){
            int start=max(j-k,0);
            int end=min(j+k,n-1);

            if(!ans.empty() && ans.back()>=start){
                start=ans.back()+1;
            }

            for(int i=start;i<=end;i++){
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main(){
    // Output: [1,2,3,4,5,6]
    vector<int>nums={3,4,9,1,3,9,5};
    int key=9,k=1;
    // Output: [0,1,2,3,4]
    vector<int>nums2={2,2,2,2,2};
    int key2=2,k2=2;
    return 0;
}