// GFG - The Knight's tour problem
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int N;
    vector<vector<int>>directions{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    bool isSafe(int i,int j){
        return i>=0 && i<N && j>=0 && j<N;
    }
    bool solve(vector<vector<int>>&ans,int i,int j,int nextStep){
        if(nextStep==N*N){
            return true;
        }
        
        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            
            if(isSafe(i_,j_) && ans[i_][j_]==-1){
                ans[i_][j_]=nextStep;
                if(solve(ans,i_,j_,nextStep+1)==true){
                    return true;
                }
                ans[i_][j_]=-1;
            }
        }
        return false;
    }
    public:
    vector<vector<int>> knightTour(int n){
        N=n;
        vector<vector<int>>ans(n,vector<int>(n,-1));
        
        ans[0][0]=0;
        
        if(solve(ans,0,0,1)==true) return ans;
        
        return {{-1}};
    }
};
int main(){
    // Output: true
    int n=5;
    // Output: true
    int n2=4;
    return 0;
}