// LC - 47 - Medium - Permutations II ( Contains Duplicates )
// 3 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Approach1{
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,unordered_map<int,int>&mp,vector<int>&temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto [num,count]:mp){
            if(count==0) continue;

            temp.push_back(num);
            mp[num]--;

            solve(nums,mp,temp);

            temp.pop_back();
            mp[num]++;
        }
    }
    public:
    vector<vector<int>> permute(vector<int>&nums){
        n=nums.size();
        unordered_map<int,int>mp;
        for(int &i:nums) mp[i]++;
        vector<int>temp;
        solve(nums,mp,temp);
        return ans;
    }
};
class Approach2{
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int idx){
        if(idx>=n){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool>visited;
        for(int i=idx;i<n;i++){
            if(visited.find(nums[i])!=visited.end()){
                continue;
            }

            visited[nums[i]]=true;
            swap(nums[idx],nums[i]);

            solve(nums,idx+1);

            swap(nums[idx],nums[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>&nums){
        n=nums.size();
        solve(nums,0);
        return ans;
    }
};
class Approach3{
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int idx){
        if(idx>=n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>uniqueSet;
        for(int i=idx;i<n;i++){
            if(uniqueSet.count(nums[i])>0){
                continue;
            }

            uniqueSet.insert(nums[i]);
            swap(nums[idx],nums[i]);

            solve(nums,idx+1);

            swap(nums[idx],nums[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>&nums){
        n=nums.size();
        solve(nums,0);
        return ans;
    }
};
int main(){
    // OP - [[1,1,2],[1,2,1],[2,1,1]]
    vector<int>nums={1,1,2};
    Approach3 obj1;
    vector<vector<int>>ans=obj1.permute(nums);
    for(auto &vec:ans){
        cout<<"[";
        for(int &i:vec) cout<<i<<" ";
        cout<<"]";
    }
    return 0;
}