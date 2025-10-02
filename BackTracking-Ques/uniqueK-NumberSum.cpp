// GFG - Unique K-Number Sum
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int N,K;
    void solve(vector<vector<int>>&ans,vector<int>temp,int sum,int idx){
        if(temp.size()==K && sum==N){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=9;i++){
            if(sum+i>N) return;
            
            temp.push_back(i);
            solve(ans,temp,sum+i,i+1);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum(int n,int k){
        N=n,K=k;
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(ans,temp,0,1);
        
        return ans;
    }
};
int main(){
    // Output: [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
    int n=9,k=3;
    // Output: []
    int n2=3,k2=3;
    return 0;
}