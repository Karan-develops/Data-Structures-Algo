// LC - 41 - HARD - First Missing Positive
// 3 Approaches
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// Approach 1 - Using Set
int bruteForce1(vector<int>&nums){
    int n=nums.size();
    long long maxE=*max_element(begin(nums),end(nums));
    maxE=max(maxE,1LL);

    unordered_set<int>st;
    for(int &i:nums) st.insert(i);

    for(int i=1;i<=maxE+1;i++){
        if(!st.count(i)) return i;
    }
    return -1;
}
// Approach 2 - Using Vector
int bruteForce2(vector<int>&nums){
    int n=nums.size();
    vector<bool>vec(n+1,false);

    for(int &i:nums){
        if(i<=n && i>=0) vec[i]=true;
    }

    for(int i=1;i<=n;i++){
        if(vec[i]==false) return i;
    }
    return n+1;
}
// Approach 3 - Constanst Space - Using Elements as Index
int firstMissingPositive(vector<int>&nums){
    int n=nums.size();
    bool containsOne=false;

    for(int i=0;i<n;i++){
        if(nums[i]==1) containsOne=true;
        
        // We only need [1,n] elements
        if(nums[i]<=0 || nums[i]>n) nums[i]=1;
    }
    
    if(containsOne==false) return 1;

    for(int i=0;i<n;i++){
        int num=abs(nums[i]);

        if(nums[num-1]<0) continue;

        nums[num-1]*=-1;
    }

    for(int i=0;i<n;i++){
        if(nums[i]>0) return i+1;
    }

    return n+1;
}
int main(){
    // Output: 3
    vector<int>nums={1,2,0};
    // Output: 2
    vector<int>nums2={3,4,-1,1};
    // Output: 1
    vector<int>nums3={7,8,9,11,12};
    cout<<firstMissingPositive(nums)<<endl;
    cout<<firstMissingPositive(nums2)<<endl;
    cout<<firstMissingPositive(nums3);
    return 0;
}