// LC - 1039 - Medium - Minimum Score Triangulation of Polygon
#include<iostream>
#include<vector>
using namespace std;
class DP{
    vector<vector<int>>dp;
    int solve(vector<int>&values,int i,int j){
        // We need atleast 3 points to make a triangle
        if(j-i+1<3){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MAX;

        for(int k=i+1;k<j;k++){
            int wt=values[i]*values[j]*values[k]+
                   solve(values,i,k)+
                   solve(values,k,j);
            
            ans=min(ans,wt);
        }

        return dp[i][j]=ans;
    }
    public:
    int minScoreTriangulation(vector<int>&values){
        int n=values.size();
        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(values,0,n-1);
    }
};
int main(){
    // Output: 6
    vector<int>values={1,2,3};
    // Output: 144
    vector<int>values2={3,7,4,5};
    // Output: 13
    vector<int>values3={1,3,1,4,1,5};

    DP sol;
    cout<<sol.minScoreTriangulation(values)<<endl;
    cout<<sol.minScoreTriangulation(values2)<<endl;
    cout<<sol.minScoreTriangulation(values3);
    return 0;
}