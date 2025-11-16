// LC - 2536 - Medium - Increment Submatrices by One
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force
class Matrix{
    void fillQueries(vector<vector<int>>&ans,int x,int y,int x_,int y_){
        for(int i=x;i<=x_;i++){
            for(int j=y;j<=y_;j++){
                ans[i][j]+=1;
            }
        }
    }
    public:
    vector<vector<int>> rangeAddQueries(int n,vector<vector<int>>&queries){
        vector<vector<int>>ans(n,vector<int>(n,0));

        for(auto &vec:queries){
            int i=vec[0];
            int j=vec[1];
            int i_=vec[2];
            int j_=vec[3];

            fillQueries(ans,i,j,i_,j_);
        }

        return ans;
    }
};
// Approach 2 - Difference Array
class DiffArray{
    public:
    vector<vector<int>> rangeAddQueries(int n,vector<vector<int>>&queries){
        vector<vector<int>>diff(n,vector<int>(n,0));

        for(auto &vec:queries){
            int row1=vec[0];
            int col1=vec[1];
            int row2=vec[2];
            int col2=vec[3];

            for(int i=row1;i<=row2;i++){
                diff[i][col1]+=1;

                if(col2+1<n){
                    diff[i][col2+1]-=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }

        return diff;
    }
};
int main(){
    // Output: [[1,1,0],[1,2,1],[0,1,1]]
    int n=3;
    vector<vector<int>>queries={{1,1,2,2},{0,0,1,1}};
    // Output: [[1,1],[1,1]]
    int n2=2;
    vector<vector<int>>queries2={{0,0,1,1}};
    return 0;
}