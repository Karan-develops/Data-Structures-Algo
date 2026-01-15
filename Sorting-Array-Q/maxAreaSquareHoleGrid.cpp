// LC - 2943 - Medium - Maximize Area of Square Hole in Grid
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximizeSquareHoleArea(int n,int m,vector<int>&hBars,vector<int>&vBars){

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