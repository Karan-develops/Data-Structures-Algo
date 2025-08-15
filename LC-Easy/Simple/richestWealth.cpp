// LC - 1672 - Easy - Richest Customer Wealth
#include<iostream>
#include<vector>
using namespace std;
int maximumWealth(vector<vector<int>>& accounts) {
    int m=accounts.size(),n=accounts[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        int money=0;
        for(int j=0;j<n;j++){
            money+=accounts[i][j];
        }
        ans=max(ans,money);
    }
    return ans;
}
int main(){
    // Output: 6
    vector<vector<int>>accounts={{1,2,3},{3,2,1}};
    // Output: 10
    vector<vector<int>>accounts2={{1,5},{7,3},{3,5}};
    // Output: 17
    vector<vector<int>>accounts3={{2,8,7},{7,1,3},{1,9,5}};
    cout<<maximumWealth(accounts)<<endl;
    cout<<maximumWealth(accounts2)<<endl;
    cout<<maximumWealth(accounts3);
    return 0;
}