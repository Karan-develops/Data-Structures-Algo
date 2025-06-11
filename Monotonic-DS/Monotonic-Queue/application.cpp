// Monotonic Queue
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Monotonic_queue{
    public:
    void minElementInKWindow(vector<int>&nums,int k){
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;

        for(int i=0;i<n;i++){
            // Out of Window Elements
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]>nums[i]){
                dq.pop_back();
            }

            // IMP** -> Pushing Index
            dq.push_back(i);
            
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        for(int &i:ans) cout<<i<<" ";
    }
};
int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};

    Monotonic_queue sol;
    sol.minElementInKWindow(nums,3);
    return 0;
}