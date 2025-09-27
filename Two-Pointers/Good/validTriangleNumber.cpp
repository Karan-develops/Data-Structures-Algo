// LC - 611 - Medium - Valid Triangle Number
// 3 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Brute Force
class BruteForce{
    bool checkValid(int &a,int &b,int &c){
        return ((a+b>c) && (a+c>b) && (b+c>a));
    }
    public:
    int triangleNumber(vector<int>&nums){
        int n=nums.size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(checkValid(nums[i],nums[j],nums[k])){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
// Approach 2 - Binary Search
class BinarySearch{
    int n;
    int binarySearch(vector<int>&nums,int &sum,int j){
        int l=j,r=n-1;
        int k=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]<sum){
                k=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return k;
    }
    public:
    int triangleNumber(vector<int>&nums){
        n=nums.size();

        sort(begin(nums),end(nums));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];

                int k=binarySearch(nums,sum,j+1);

                if(k!=-1) ans+=(k-j);
            }
        }
        return ans;
    }
};
// Approach 3 - Two Pointers
int triangleNumber(vector<int>&nums){
    int n=nums.size();

    sort(begin(nums),end(nums));
    int ans=0;

    for(int k=n-1;k>=0;k--){
        int i=0,j=k-1;

        while(i<j){
            if(nums[i]+nums[j]>nums[k]){
                ans+=(j-i);
                j--;
            } else{
                i++;
            }
        }
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={2,2,3,4};
    // Output: 4
    vector<int>nums2={4,2,3,4};
    cout<<triangleNumber(nums)<<endl;
    cout<<triangleNumber(nums2);
    return 0;
}