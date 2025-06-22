// LC - 2672 - Medium - Number of Adjacent Elements With the Same Color
#include<iostream>
#include<vector>
using namespace std;
vector<int> colorTheArray(int n,vector<vector<int>>&queries){
    vector<int>nums(n,0);
    vector<int>ans;

    int count=0;

    for(auto &vec:queries){
        int idx=vec[0];
        int color=vec[1];

        // Decrease count if already had adjacent same-colored pair
        if(nums[idx]!=0){
            if(idx>0 && nums[idx]==nums[idx-1]) count--;
            if(idx+1<n && nums[idx]==nums[idx+1]) count--;
        }

        nums[idx]=color; // Color it
        // Increase count for new adjacent same-colored pair
        if(idx>0 && nums[idx]==nums[idx-1]) count++;
        if(idx+1<n && nums[idx]==nums[idx+1]) count++;

        ans.push_back(count);
    }
    return ans;
}
int main(){
    // Output: [0,1,1,0,2]
    int n=4;
    vector<vector<int>>queries={{0,2},{1,2},{3,1},{1,1},{2,1}};
    // Output: [0]
    int n2=1;
    vector<vector<int>>queries2={{0,100000}};
    return 0;
}