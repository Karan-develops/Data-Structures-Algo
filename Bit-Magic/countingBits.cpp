// LC - 338 - Easy - Counting Bits
#include<iostream>
#include<vector>
using namespace std;
vector<int> countBits(int n) {
    vector<int>ans(n+1);
    for(int i=0;i<=n;i++){
        ans[i]=__builtin_popcount(i);
    }
    return ans;
}
int main(){
    // Output: [0,1,1]
    int n=2;
    // Output: [0,1,1,2,1,2]
    int n2=5;
    vector<int>ans=countBits(n2);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}