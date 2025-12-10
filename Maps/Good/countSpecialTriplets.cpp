// LC - 3583 - Medium - Count Special Triplets
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Approach 1 - Two Pass
class Maps{
    const int M=1e9+7;
    public:
    int specialTriplets(vector<int>&nums){
        unordered_map<int,int>mp_left;
        unordered_map<int,int>mp_right;

        int ans=0;

        for(int &i:nums){
            mp_right[i]++;
        }

        for(int &i:nums){
            mp_right[i]--;

            int left=mp_left[i*2];
            int right=mp_right[i*2];

            ans=(ans+(1LL*left*right))%M;

            mp_left[i]++;
        }

        return ans;
    }
};
// Approach 2 - One Pass
class Optimal{
    const int M=1e9+7;
    public:
    int specialTriplets(vector<int>&nums){
        unordered_map<int,int>valid_i;
        unordered_map<int,int>valid_j;

        int ans=0;

        for(int &i:nums){
            // if it's valid k, we got our triplet
            if(i%2==0){
                ans=(ans+valid_j[i/2])%M;
            }

            // if it's valid j or not
            valid_j[i]=(valid_j[i]+valid_i[i*2])%M;

            valid_i[i]++;
        }

        return ans;
    }
};
int main(){
    // Output: 1
    vector<int>nums={6,3,6};
    // Output: 1
    vector<int>nums2={0,1,0,0};
    // Output: 2
    vector<int>nums3={8,4,2,8,4};

    Maps sol;
    cout<<sol.specialTriplets(nums)<<endl;
    cout<<sol.specialTriplets(nums2)<<endl;
    cout<<sol.specialTriplets(nums3);
    return 0;
}