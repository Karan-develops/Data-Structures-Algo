// LC - 1424 - Medium - Diagonal Traverse II
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// Approach 1 - Using Map [i+j] Concept
vector<int> findDiagonalOrder(vector<vector<int>>&nums){
    unordered_map<int,vector<int>>mp;
    
    // Traverse Backwards - Last Row - First Col
    for(int i=nums.size()-1;i>=0;i--){
        for(int j=0;j<nums[i].size();j++){
            mp[i+j].push_back(nums[i][j]);
        }
    }
    
    vector<int>ans;
    int diagonal=0;
    
    while(mp.find(diagonal)!=mp.end()){
        for(int &num:mp[diagonal]){
            ans.push_back(num);
        }
        diagonal++;
    }
    return ans;
}
// Approach 2 - Using BFS
vector<int> findDiagonalOrder(vector<vector<int>>&nums){
    queue<pair<int,int>>q;
    q.push({0,0});

    vector<int>ans;
    
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();

        ans.push_back(nums[i][j]);
        
        // Below Ngbr
        // j==0 --> to avoid duplicates
        if(j==0 && i<nums.size()-1){
            q.push({i+1,j});
        }
        
        // Right Ngbr
        if(j<nums[i].size()-1){
            q.push({i,j+1});
        }
    }
    return ans;
}
int main(){
    // Output: [1,4,2,7,5,3,8,6,9]
    vector<vector<int>>nums={{1,2,3},{4,5,6},{7,8,9}};
    // Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
    vector<vector<int>>nums2={{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    return 0;
}