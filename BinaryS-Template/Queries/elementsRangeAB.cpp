// GFG - Medium - Elements in range [a, b]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> cntInRange(vector<int>&arr,vector<vector<int>>&queries){
    sort(begin(arr),end(arr));
    
    vector<int>ans;

    for(auto &vec:queries){
        int a=vec[0];
        int b=vec[1];
        
        int left=lower_bound(begin(arr),end(arr),a)-begin(arr);
        int right=upper_bound(begin(arr),end(arr),b)-begin(arr);
        
        ans.push_back(right-left);
    }
    
    return ans;
}
int main(){
    // Output: [3, 2, 5]
    vector<int>arr={1,4,2,8,5};
    vector<vector<int>>queries={{1,4},{3,6},{0,10}};
    // Output: [1, 2, 5]
    vector<int>arr2={10,20,30,40,50};
    vector<vector<int>>queries2={{5,15},{25,45},{10,50}};
    return 0;
}