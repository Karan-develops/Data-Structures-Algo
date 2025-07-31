// LC - 898 - Medium - Bitwise ORs of Subarrays
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int subarrayBitwiseORs(vector<int>&arr){
    unordered_set<int>prev,curr,ans;

    for(int &i:arr){
        // Max size of prev will be 32
        for(int x:prev){
            curr.insert(i|x);
            ans.insert(i|x);
        }
        curr.insert(i);
        ans.insert(i);
        prev=curr;
        curr.clear();
    }
    return ans.size();
}
int main(){
    // Output: 1
    vector<int>arr={0};
    // Output: 3
    vector<int>arr2={1,1,2};
    // Output: 6
    vector<int>arr3={1,2,4};
    cout<<subarrayBitwiseORs(arr)<<endl;
    cout<<subarrayBitwiseORs(arr2)<<endl;
    cout<<subarrayBitwiseORs(arr3);
    return 0;
}