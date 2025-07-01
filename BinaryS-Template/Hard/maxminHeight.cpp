// GFG - Max min Height
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    bool isPossible(vector<int>&nums,int k,int w,int mid){
        int n=nums.size();
        
        vector<int>water(n+1,0);
        int daysUsed=0;
        int currWater=0;
        
        for(int i=0;i<n;i++){
            currWater+=water[i];
            int currHeight=nums[i]+currWater;
            
            if(currHeight<mid){
                int need=mid-currHeight;

                daysUsed+=need;
                currWater+=need;
                
                if(daysUsed>k) return false;

                // Difference Array
                water[i]+=need;
                if(i+w<=n) water[i+w]-=need;
            }
        }
        return true;
    }
    public:
    int maxMinHeight(vector<int>&nums,int k,int w){
        int l=*min_element(begin(nums),end(nums));
        int r=l+k;
        
        int ans=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(isPossible(nums,k,w,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};