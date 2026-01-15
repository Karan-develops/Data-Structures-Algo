// LC - 2943 - Medium - Maximize Area of Square Hole in Grid
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximizeSquareHoleArea(int n,int m,vector<int>&hBars,vector<int>&vBars){
    sort(begin(hBars),end(hBars));
    sort(begin(vBars),end(vBars));

    int maxConsecutiveHBars=1;
    int maxConsecutiveVBars=1;

    // First find Length of Longest consecutive horizontal bars
    int currConsecutiveHBars=1;

    for(int i=1;i<hBars.size();i++){
        if(hBars[i]-hBars[i-1]==1){
            currConsecutiveHBars++;
        } else{
            currConsecutiveHBars=1;
        }
        maxConsecutiveHBars=max(maxConsecutiveHBars,currConsecutiveHBars);
    }

    // Similarly, find Length of Longest consecutive vertical bars
    int currConsecutiveVBars=1;

    for(int i=1;i<vBars.size();i++){
        if(vBars[i]-vBars[i-1]==1){
            currConsecutiveVBars++;
        } else{
            currConsecutiveVBars=1;
        }
        maxConsecutiveVBars=max(maxConsecutiveVBars,currConsecutiveVBars);
    }

    // Square width and height must be same. We can reduce the larger one to match the smaller one
    // So, take the minimum of them.
    int side=min(maxConsecutiveHBars,maxConsecutiveVBars)+1;
    
    return side*side;
}
int main(){
    // Output: 4
    int n=2,m=1;
    vector<int>hBars={2,3},vBars={2};
    // Output: 4
    int n2=1,m2=1;
    vector<int>hBars2={2},vBars2={2};
    // Output: 4
    int n3=2,m3=3;
    vector<int>hBars3={2,3},vBars3={2,4};
    cout<<maximizeSquareHoleArea(n,m,hBars,vBars)<<endl;
    cout<<maximizeSquareHoleArea(n2,m2,hBars2,vBars2)<<endl;
    cout<<maximizeSquareHoleArea(n3,m3,hBars3,vBars3);
    return 0;
}