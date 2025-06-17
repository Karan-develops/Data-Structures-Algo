// LC - 2966 - Medium - Divide Array Into Arrays With Max Difference
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> divideArray(vector<int>&nums,int k){
    int n=nums.size();
    vector<vector<int>>ans;

    sort(begin(nums),end(nums));

    for(int i=0;i<n;i+=3){
        int minVal=nums[i],maxVal=nums[i];
        vector<int>temp;

        for(int j=i;j<i+3;j++){
            minVal=min(minVal,nums[j]);
            maxVal=min(maxVal,nums[j]);
            temp.push_back(nums[j]);
        }
        
        if(abs(minVal-maxVal)>k) return {};
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    // Output: [[1,1,3],[3,4,5],[7,8,9]]
    vector<int>nums={1,3,4,8,7,9,3,5,1};
    int k=2;
    // Output: []
    vector<int>nums2={2,4,2,2,5,2};
    int k2=2;
    // Output: [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]
    vector<int>nums3={4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    int k3=14;
    return 0;
}