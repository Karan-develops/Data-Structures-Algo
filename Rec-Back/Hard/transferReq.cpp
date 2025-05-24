// LC - 1601 - HARD - Maximum Number of Achievable Transfer Requests
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int N,ans;
    void solve(vector<vector<int>>&req,vector<int>&net,int count,int i){
        if(i==req.size()){
            for(int x:net){
                if(x!=0) return;
            }
            ans=max(ans,count);
            return;
        }
        net[req[i][0]]--;
        net[req[i][1]]++;
        solve(req,net,count+1,i+1);
        net[req[i][0]]++;
        net[req[i][1]]--;

        // Skip current request
        solve(req,net,count,i+1);
    }
    public:
    int maximumRequests(int n,vector<vector<int>>&requests){
        N=n,ans=0;
        vector<int>net(n,0);
        solve(requests,net,0,0);
        return ans;
    }
};
int main(){
    // Output: 5
    int n=5;
    vector<vector<int>>requests={{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    // Output: 3
    int n2=3;
    vector<vector<int>>requests2={{0,0},{1,2},{2,1}};
    // Output: 4
    int n3=4;
    vector<vector<int>>requests3={{0,3},{3,1},{1,2},{2,0}};
    Solution sol;
    cout<<sol.maximumRequests(n,requests)<<endl;
    cout<<sol.maximumRequests(n2,requests2)<<endl;
    cout<<sol.maximumRequests(n3,requests3);
    return 0;
}
