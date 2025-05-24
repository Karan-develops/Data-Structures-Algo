// LC - 2433 - Medium - Find The Original Array of Prefix Xor
#include<iostream>
#include<vector>
using namespace std;
// Approach 1
vector<int> findArray(vector<int>& pref) {
    int n=pref.size();
    vector<int>ans(n,0);

    ans[0]=pref[0];
    for(int i=1;i<n;i++){
        ans[i]=pref[i-1]^pref[i];
    }
    return ans;
}
// Approach 2 - Constant Space
vector<int> findArray2(vector<int>& pref) {
    int n=pref.size();

    for(int i=n-1;i>0;i--){
        pref[i]=pref[i-1]^pref[i];
    }
    return pref;
}
int main(){
    // Output: [5,7,2,3,2]
    vector<int>pref={5,2,0,3,1};
    // Output: [13]
    vector<int>pref2={13};
    return 0;
}