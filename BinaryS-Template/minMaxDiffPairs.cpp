// LC - 2616 - Medium - Minimize the Maximum Difference of Pairs
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int n;
    bool isValid(vector<int>&nums,int mid,int p){
        int i=0;
        int pairs=0;

        while(i<n-1){
             if(abs(nums[i]-nums[i+1])<=mid){
                pairs++;
                i+=2;
            } else{
                i++;
            }
        }
        return pairs>=p;
    }
    public:
    int minimizeMax(vector<int>&nums,int p){
        n=nums.size();

        sort(begin(nums),end(nums));

        int l=0,r=nums[n-1]-nums[0];
        int ans=INT_MAX;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(isValid(nums,mid,p)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 1
    vector<int>nums={10,1,2,7,1,3};
    int p=2;
    // Output: 0
    vector<int>nums2={4,2,1,2};
    int p2=1;

    BinarySearch sol;
    cout<<sol.minimizeMax(nums,p)<<endl;
    cout<<sol.minimizeMax(nums2,p2);
    return 0;
}