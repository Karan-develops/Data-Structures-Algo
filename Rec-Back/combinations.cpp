// LC - 77 - Medium - Combinations
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    void solve(vector<vector<int>>&ans,vector<int>&temp,int n,int k,int idx){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            solve(ans,temp,n,k,i+1);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combine(int n,int k){

    }
};
int main(){
    // Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    int n=4,k=2;
    // Output: [[1]]
    int n=1,k=1;
    return 0;
}