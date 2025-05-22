// LC - 2471 - Medium - Minimum Number of Operations to Sort a Binary Tree by Level
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class BFS{
    int solve(vector<int>&nums){
        int swaps;

        vector<int>sortedArr(begin(nums),end(nums));
        sort(begin(sortedArr),end(sortedArr));

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
        mp[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            // No Swaps Required
            if(nums[i]==sortedArr[i]) continue;

            int currIdx=mp[sortedArr[i]];
            mp[nums[i]]=currIdx;
            mp[nums[currIdx]]=i;
            swap(nums[i],nums[currIdx]);
            swaps++;
        }
        return swaps;
    }
    public:
    int minimumOperations(Node* root){
        int ans=0;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            vector<int>v;
            while(N--){
                Node* currNode=q.front();
                q.pop();

                v.push_back(currNode->data);

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            ans+=solve(v);
        }
        return ans;
    }
};
/*
Example 1:
Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
----------------
Example 2:
Input: root = [1,3,2,7,6,5,4]
Output: 3
----------------
Example 3:
Input: root = [1,2,3,4,5,6]
Output: 0
*/