// LC - 3678 - Easy - Smallest Absent Positive Greater Than Average
#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include<unordered_set>
using namespace std;
int smallestAbsent(vector<int>&nums){
    int n=nums.size();

    int sum=accumulate(begin(nums),end(nums),0);
    double avg=(double)sum/n;

    unordered_set<int>st(begin(nums),end(nums));

    int ans=max(1,(int)floor(avg)+1);

    while(st.count(ans)){
        ans++;
    }

    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={3,5};
    // Output: 3
    vector<int>nums2={-1,1,2};
    // Output: 2
    vector<int>nums3={4,-1};
    cout<<smallestAbsent(nums)<<endl;
    cout<<smallestAbsent(nums2)<<endl;
    cout<<smallestAbsent(nums3);
    return 0;
}