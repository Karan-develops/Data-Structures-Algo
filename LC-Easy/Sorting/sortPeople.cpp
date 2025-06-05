// LC - 2418 - Easy - Sort the People
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<string>ans;
    
    vector<pair<int,int>>v;
    for(int i=0;i<heights.size();i++){
        v.push_back({heights[i],i});
    }

    auto lambda=[&](auto &x,auto &y){
        return x.first>y.first;
    };
    sort(begin(v),end(v),lambda);

    for(auto &it:v){
        ans.push_back(names[it.second]);
    }
    return ans;
}
int main(){
    // Output: ["Mary","Emma","John"]
    vector<string>names={"Mary","John","Emma"};
    vector<int>heights={180,165,170};
    // Output: ["Bob","Alice","Bob"]
    vector<string>names2={"Alice","Bob","Bob"};
    vector<int>heights2={155,185,150};
    return 0;
}