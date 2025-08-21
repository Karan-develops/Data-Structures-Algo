// LC - 1504 - Medium - Count Submatrices With All Ones
// Also solved using Monotonic Stack
#include<iostream>
#include<vector>
using namespace std;
class TwoDArray{
    int oneDArraySubMatrix(vector<int>&vec){
        int count=0;
        int consecutiveCount=0;

        for(int &i:vec){
            if(i==1){
                count+=consecutiveCount+1;
                consecutiveCount+=1;
            } else{
                consecutiveCount=0;
            }
        }
        return count;
    }
    public:
    int numSubmat(vector<vector<int>>&mat){
        int m=mat.size();
        int n=mat[0].size();

        int ans=0;

        for(int startRow=0;startRow<m;startRow++){
            vector<int>v(n,1);
            for(int endRow=startRow;endRow<m;endRow++){
                for(int col=0;col<n;col++){
                    v[col]=v[col]&mat[endRow][col];
                }
                ans+=oneDArraySubMatrix(v);
            }
        }
        return ans;
    }
};
int main(){
    // Output: 13
    vector<vector<int>>mat={{1,0,1},{1,1,0},{1,1,0}};
    // Output: 24
    vector<vector<int>>mat2={{0,1,1,0},{0,1,1,1},{1,1,1,0}};

    TwoDArray sol;
    cout<<sol.numSubmat(mat)<<endl;
    cout<<sol.numSubmat(mat2);
    return 0;
}