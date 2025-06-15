// LC - 2439 - Medium - Minimize Maximum of Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int n;
    bool isValid(vector<int>&nums,int mid){
        vector<long long>temp(begin(nums),end(nums));

        for(int i=0;i<n-1;i++){
            if(temp[i]>mid) return false;

            long long buffer=mid-temp[i];
            temp[i+1]-=buffer;
        }
        return temp[n-1]<=mid;
    }
    public:
    int minimizeArrayValue(vector<int>&nums){
        n=nums.size();

        int l=0;
        int r=*max_element(begin(nums),end(nums));
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(isValid(nums,mid)){
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
    // Output: 5
    vector<int>nums={3,7,1,6};
    // Output: 10
    vector<int>nums2={10,1};

    BinarySearch sol;
    cout<<sol.minimizeArrayValue(nums)<<endl;
    cout<<sol.minimizeArrayValue(nums2);
    return 0;
}