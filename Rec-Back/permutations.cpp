// LC - 46 - Medium
// 2 Approaches - Set - Swap
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class SetPermute{
    int n;
    unordered_set<int>st;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&temp){
        if(temp.size()>=n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                temp.push_back(nums[i]);

                solve(nums,temp);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int>&nums){
        n=nums.size();
        vector<int>temp;
        solve(nums,temp);
        return ans;
    }
};
class SwapPermute{
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int idx){
        if(idx>=n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
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
    vector<int>nums={1,2,3};
    SetPermute obj1;
    vector<vector<int>>ans1=obj1.permute(nums);
    SwapPermute obj2;
    vector<vector<int>>ans2=obj2.permute(nums);
    for(auto &vec:ans1){
        cout<<"[";
        for(int &i:vec) cout<<i<<" ";
        cout<<"]";
    }
    cout<<endl;
    for(auto &vec:ans2){
        cout<<"[";
        for(int &i:vec) cout<<i<<" ";
        cout<<"]";
    }
    return 0;
}