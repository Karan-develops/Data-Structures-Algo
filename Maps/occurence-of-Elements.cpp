// LC - 3159 - Medium - Find Occurrences of an Element in an Array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    int n=nums.size();
    vector<int>ans;
    unordered_map<int,int>mp;

    int idxCount=1;
    for(int i=0;i<n;i++){
        if(nums[i]==x){
            mp[idxCount++]=i;
        }
    }

    for(int &q:queries){
        if(mp.count(q)){
            ans.push_back(mp[q]);
        } else{
            ans.push_back(-1);
        }
    }
    return ans;
}
int main(){
    // Output: [0,-1,2,-1]
    vector<int>nums={1,3,1,7},queries={1,3,2,4};
    int x=1;
    // Output: [-1]
    vector<int>nums2={1,2,3},queries2={10};
    int x2=5;
    return 0;
}