// LC - 995 - HARD - Minimum Number of K Consecutive Bit Flips
// GFG - Minimum K Consecutive Bit Flips
/*
- Similar Qn : https://github.com/Karan-develops/Data-Structures-Algo/blob/main/Bit-Magic/LC3191.cpp
*/ 
// 3 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force
// T.C - O(n*k)
class BruteForce{
    public:
    int minKBitFlips(vector<int>&nums,int k){
        int n=nums.size();

        int ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                for(int j=i;j<i+k;j++){
                    if(i+k>n) return -1;
                    
                    nums[j]=1-nums[j];
                }
                ans++;
            }
        }
        return ans;
    }
};
// Approach 2 - Using Space
class Solution{
    public:
    int minKBitFlips(vector<int>&nums,int k){
        /* Flip-Count (ODD):
            nums[i]=1 => Flip
            nums[i]=0 => No-Flip
        */
        /* Flip-Count (EVEN):
            nums[i]=1 => No-Flip
            nums[i]=0 => Flip
        */
        /* Consolidate
           (Flip-Count%2==nums[i]) => Flip
        */
        int n=nums.size();

        vector<bool>flipped(n,false);
        int pastFlipCountFromPastI=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(i>=k && flipped[i-k]==true){
                pastFlipCountFromPastI--;
            }

            if(pastFlipCountFromPastI%2==nums[i]){
                if(i+k>n) return -1;
                
                pastFlipCountFromPastI++;
                flipped[i]=true;
                ans++;
            }
        }
        return ans;
    }
};
// Approach 3 - No Space
class Optimized{
    public:
    int minKBitFlips(vector<int>&nums,int k){
        int n=nums.size();

        int pastFlipCountFromPastI=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==2){
                pastFlipCountFromPastI--;
            }

            if(pastFlipCountFromPastI%2==nums[i]){
                if(i+k>n) return -1;
                
                pastFlipCountFromPastI++;
                nums[i]=2;
                ans++;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 2
    vector<int>nums={0,1,0};
    int k=1;
    // Output: -1
    vector<int>nums2={1,1,0};
    int k2=2;
    // Output: 3
    vector<int>nums3={0,0,0,1,0,1,1,0};
    int k3=3;

    Optimized sol;
    cout<<sol.minKBitFlips(nums,k)<<endl;
    cout<<sol.minKBitFlips(nums2,k2)<<endl;
    cout<<sol.minKBitFlips(nums3,k3);
    return 0;
}