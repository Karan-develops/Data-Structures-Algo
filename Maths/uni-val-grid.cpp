// LC - 2033 - Medium - Minimum Operations to Make a Uni-Value Grid
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minOperations(vector<vector<int>>&grid,int x){
    vector<int>vec;
    for(auto &v:grid){
        for(auto &i:v) vec.push_back(i);
    }

    sort(begin(vec),end(vec));

    int ans=0,n=grid.size();
    int midTarget=vec[n/2];

    for(auto &i:vec){
        if(midTarget%x != i%x) return -1;
        ans+=abs(midTarget-i)/x;
    }
    return ans;
}
int main(){
    // Output: 4
    vector<vector<int>>grid={{2,4},{6,8}};
    int x=2;
    // Output: 5
    vector<vector<int>>grid2={{1,5},{2,3}};
    int x2=1;
    // Output: -1
    vector<vector<int>>grid3={{1,2},{3,4}};
    int x3=2;
    cout<<minOperations(grid,x)<<endl;
    cout<<minOperations(grid2,x2)<<endl;
    cout<<minOperations(grid3,x3);
    return 0;
}