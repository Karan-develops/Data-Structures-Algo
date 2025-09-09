// LC - 1304 - Easy - Find N Unique Integers Sum up to Zero
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1
vector<int> sumZero(int n){
    if(n==0) return {};

    vector<int>ans(n);
    int temp=n;

    for(int i=0;i<n/2;i++){
        ans[i]=-temp;
        ans[n-i-1]=temp;
        temp--;
    }
    if(n&1) ans[n/2]=0;

    return ans;
}
// Approach 2
vector<int> sumZero2(int n){
    vector<int>ans;

    if(n&1) ans.push_back(0);

    for(int i=0;i<n/2;i++){
        ans.push_back(i);
        ans.push_back(-i);
    }
    return ans;
}
int main(){
    // Output: [-7,-1,1,3,4]
    int n=5;
    // Output: [-1,0,1]
    int n2=3;
    // Output: [0]
    int n3=1;
    return 0;
}