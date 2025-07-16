// LC - 216 - Medium - Combination Sum III
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    void solve(vector<vector<int>>&ans,vector<int>temp,int k,int n,int start){
        if(k==0 && n==0){
            ans.push_back(temp);
        }

        for(int i=start;i<=9;i++){
            if(i>n) break;

            temp.push_back(i);
            solve(ans,temp,k-1,n-i,i+1);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans,temp,k,n,1);
        return ans;
    }
};
int main(){
    // Output: [[1,2,4]]
    int k=3,n=7;
    // Output: [[1,2,6],[1,3,5],[2,3,4]]
    int k2=3,n2=9;
    // Output: []
    int k3=4,n3=1;
    return 0;
}