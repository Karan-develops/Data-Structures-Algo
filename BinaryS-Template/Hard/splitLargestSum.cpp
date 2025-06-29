// GFG - Split numsay Largest Sum
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class BinarySearch{
    bool isPossible(vector<int>&nums,int k,int mid){
        int count=1,currSum=0;
        
        for(int &i:nums){
            if(currSum+i>mid){
                count++;
                currSum=0;
            } else if(count>k){
                return false;
            }
            currSum+=i;
        }
        return count<=k;
    }
    public:
    int splitArray(vector<int>&nums,int k){
        int l=*max_element(begin(nums),end(nums));
        int r=accumulate(begin(nums),end(nums),0);
        
        int ans=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(isPossible(nums,k,mid)){
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
    // Output: 4
    vector<int>nums={1,2,3,4};
    int k=3;
    // Output: 2
    vector<int>nums2={1,1,2};
    int k2=2;

    BinarySearch sol;
    cout<<sol.splitArray(nums,k)<<endl;
    cout<<sol.splitArray(nums2,k2);
    return 0;
}