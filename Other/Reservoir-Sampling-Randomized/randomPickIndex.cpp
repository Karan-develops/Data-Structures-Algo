// LC - 398 - Medium - Random Pick Index
#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;
class Solution{
    unordered_map<int,vector<int>>mp;
    public:
    Solution(vector<int>&nums){
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
    }
    int pick(int target){
        vector<int>temp=mp[target];
        return temp[rand()%temp.size()];
    }
};
/*
- Input:
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
- Output:
[null, 4, 0, 2]
*/