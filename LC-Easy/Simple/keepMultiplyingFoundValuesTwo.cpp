// LC - 2154 - Easy - Keep Multiplying Found Values by Two
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int findFinalValue(vector<int>&nums,int original){
    unordered_set<int>st(begin(nums),end(nums));

    while(st.count(original)){
        original*=2;
    }

    return original;
}
int main(){
    // Output: 24
    vector<int>nums={5,3,6,1,12};
    int original=3;
    // Output: 4
    vector<int>nums2={2,7,9};
    int original2=4;
    cout<<findFinalValue(nums,original)<<endl;
    cout<<findFinalValue(nums2,original2);
    return 0;
}