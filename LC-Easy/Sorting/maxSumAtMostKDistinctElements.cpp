// LC - 3684 - Easy - Maximize Sum of At Most K Distinct Elements
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
vector<int> maxKDistinct(vector<int>&nums,int k){
    unordered_set<int>st(begin(nums),end(nums));
    
    vector<int>temp(begin(st),end(st));

    sort(begin(temp),end(temp),greater<>());
    nums.clear();

    int i=0;
    while(k-- && i<temp.size()){
        nums.push_back(temp[i++]);
    }
    return nums;
}
int main(){
    // Output: [100,93,90]
    vector<int>nums={84,93,100,77,90};
    int k=3;
    // Output: [100,93,84]
    vector<int>nums2={84,93,100,77,93};
    int k2=3;
    // Output: [2,1]
    vector<int>nums3={1,1,1,2,2,2};
    int k3=6;
    return 0;
}