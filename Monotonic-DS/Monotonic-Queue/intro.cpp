// Monotonic Queue
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Monotonic_queue{
    public:
    void monotonicIncreasing(vector<int>&nums){
        int n=nums.size();
        deque<int>dq;

        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]>nums[i]){
                dq.pop_back();
            }
            // IMP** --> Pushing Index
            dq.push_back(i);
        }

        while(!dq.empty()){
            cout<<nums[dq.front()]<<" ";
            dq.pop_front();
        }
        cout<<endl;
    }
    void monotonicDecreasing(vector<int>&nums){
        int n=nums.size();
        deque<int>dq;

        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            // IMP** --> Pushing Index
            dq.push_back(i);
        }

        while(!dq.empty()){
            cout<<nums[dq.front()]<<" ";
            dq.pop_front();
        }
        cout<<endl;
    }
};
int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};

    Monotonic_queue sol;
    sol.monotonicIncreasing(nums);
    sol.monotonicDecreasing(nums);
    return 0;
}