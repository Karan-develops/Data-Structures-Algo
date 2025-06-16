// GFG - Smallest Divisor
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    bool checkValid(vector<int>&nums,int k,int mid){
        int sum=0;
        
        for(int &i:nums){
            sum+=(i+mid-1)/mid;
        }
        return sum<=k;
    }
    public:
    int smallestDivisor(vector<int>&arr,int k){
        int l=1;
        int r=*max_element(begin(arr),end(arr));
        int ans=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(checkValid(arr,k,mid)){
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
    vector<int>arr={1,2,5,9};
    int k=6;
    // Output: 1
    vector<int>arr2={1,1,1,1};
    int k2=4;

    BinarySearch sol;
    cout<<sol.smallestDivisor(arr,k)<<endl;
    cout<<sol.smallestDivisor(arr2,k2);
    return 0;
}