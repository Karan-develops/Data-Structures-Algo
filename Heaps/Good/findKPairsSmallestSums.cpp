// LC - 373 - Medium - Find K Pairs with Smallest Sums
// GFG - Medium - Find K Smallest Sum Pairs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Heap{
    // {sum,i,j}
    typedef tuple<int,int,int>T;
    public:
    vector<vector<int>> kSmallestPairs(vector<int>&nums1,vector<int>&nums2,int k){
        vector<vector<int>>ans;

        if(nums1.empty() || nums2.empty() || k==0){
            return ans;
        }

        priority_queue<T,vector<T>,greater<>>pq;

        for(int i=0;i<nums1.size() && i<k;i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }

        while(k-- && !pq.empty()){
            auto [sum,i,j]=pq.top();
            pq.pop();

            ans.push_back({nums1[i],nums2[j]});

            if(j+1<nums2.size()){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }
        }

        return ans;
    }
};
int main(){
    // Output: [[1,2],[1,4],[1,6]]
    vector<int>nums1={1,7,11},nums2={2,4,6};
    int k=3;
    // Output: [[1,1],[1,1]]
    vector<int>nums3={1,1,2},nums4={1,2,3};
    int k2=2;
    return 0;
}