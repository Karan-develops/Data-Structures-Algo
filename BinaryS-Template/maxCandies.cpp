// LC - 2226 - Medium - Maximum Candies Allocated to K Children
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int N;
    bool canDistr(vector<int>&candies,long long k,int mid){
        for(int i=0;i<N;i++){
            // Distributing candies
            k-=candies[i]/mid;

            // Early return - All children got mid candies
            if(k<=0) return true;
        }
        // All children got the mid candies
        return k<=0;
    }
    public:
    int maximumCandies(vector<int>&candies,long long k){
        N=candies.size();
        int maxC=0;
        long long total=0;
        for(int &i:candies){
            total+=i;
            maxC=max(maxC,i);
        }
        if(total<k) return 0;
        int l=1;
        int r=maxC;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canDistr(candies,k,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    // OP - 5
    vector<int>candies1={5,8,6};
    long long k1=3;
    // OP - 0
    vector<int>candies2={2,5};
    long long k2=11;
    Solution sol;
    cout<<sol.maximumCandies(candies1,k1)<<endl;
    cout<<sol.maximumCandies(candies2,k2);
    return 0;
}