// LC - 2040 - HARD - Kth Smallest Product of Two Sorted Arrays
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    int n;
    typedef long long ll;
    ll findCountSmallest(vector<int>&nums1,vector<int>&nums2,ll midProduct){
        ll count=0;

        for(int i=0;i<nums1.size();i++){
            // Fixing nums[i]

            if(nums1[i]>=0){
                int l=0;
                int r=n-1;
                int m=-1; // Invalid Index on Left Side

                while(l<=r){
                    int mid=l+(r-l)/2;

                    ll prod=1LL*nums1[i]*nums2[mid];

                    if(prod<=midProduct){
                        m=mid;
                        l=mid+1;
                    } else{
                        r=mid-1;
                    }
                }
                count+=(m+1);
            } else{
                int l=0;
                int r=n-1;
                int m=n; // Invalid Index in right

                while(l<=r){
                    int mid=l+(r-l)/2;

                    ll prod=1LL*nums1[i]*nums2[mid];

                    if(prod<=midProduct){
                        m=mid;
                        r=mid-1;
                    } else{
                        l=mid+1;
                    }
                }
                count+=(n-m);
            }
        }
        return count;
    }
    public:
    long long kthSmallestProduct(vector<int>&nums1,vector<int>&nums2,long long k){
        n=nums2.size();
        // Minimum Possible Product
        ll l=-1e10;
        // Maximum Possible Product
        ll r=1e10;

        ll ans=0;

        while(l<=r){
            ll midProduct=l+(r-l)/2;

            ll countSmallest=findCountSmallest(nums1,nums2,midProduct);

            if(countSmallest>=k){
                ans=midProduct;
                r=midProduct-1;
            } else{
                l=midProduct+1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 8
    vector<int>nums1={2,5},nums2={3,4};
    int k=2;
    // Output: 0
    vector<int>nums3={-4,-2,0,3},nums4={2,4};
    int k2=6;
    // Output: -6
    vector<int>nums5={-2,-1,0,1,2},nums6={-3,-1,2,4,5};
    int k3=3;

    BinarySearch sol;
    cout<<sol.kthSmallestProduct(nums1,nums2,k)<<endl;
    cout<<sol.kthSmallestProduct(nums3,nums4,k2)<<endl;
    cout<<sol.kthSmallestProduct(nums5,nums6,k3);
    return 0;
}