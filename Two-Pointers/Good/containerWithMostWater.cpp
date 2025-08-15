// LC - 11 - Medium - Container With Most Water
#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>&height){
    int n=height.size();

    int i=0,j=n-1;
    int maxArea=0;

    while(i<j){
        int w=j-i;
        int h1=height[i],h2=height[j];
        int h=min(h1,h2);
        
        maxArea=max(maxArea,h*w);
        h1>h2?j--:i++;
    }
    return maxArea;
}
int main(){
    // Output: 49
    vector<int>height={1,8,6,2,5,4,8,3,7};
    // Output: 1
    vector<int>height2={1,1};
    cout<<maxArea(height)<<endl;
    cout<<maxArea(height2);
    return 0;
}