#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>&height){
    int n=height.size();
    if(n<=2) return 0;
    int ans=0;
    vector<int>leftMax(n);
    vector<int>rightMax(n);
    int maxi=height[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi,height[i]);
        leftMax[i]=max(height[i],maxi);
    }
    maxi=height[n-1];
    for(int i=n-2;i>=0;i--){
        maxi=max(maxi,height[i]);
        rightMax[i]=max(height[i],maxi);
    }
    for(int i=1;i<n-1;i++){
        ans=ans+min(leftMax[i],rightMax[i])-height[i];
    }
    return ans;
}
int main(){
    vector<int>heights{4,2,0,5,2,6,2,3};
    cout<<trap(heights);
    return 0;
}