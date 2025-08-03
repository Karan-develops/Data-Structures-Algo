// GFG - 2D Difference Array
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> applyDiff2D(vector<vector<int>>&mat,vector<vector<int>>&opr){
                                        
    int m=mat.size(),n=mat[0].size();
    vector<vector<int>>diff(m+1,vector<int>(n+1,0));

    for (auto &vec:opr){
        int val=vec[0];
        int r1=vec[1],c1=vec[2];
        int r2=vec[3],c2=vec[4];

        diff[r1][c1]+=val;
        
        if(r2+1<m) diff[r2+1][c1]-=val;
        if(c2+1<n) diff[r1][c2+1]-=val;
        if(r2+1<m && c2+1<n) diff[r2+1][c2+1]+=val;
    }

    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            diff[i][j]+=diff[i][j-1];
        }
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<m;i++){
            diff[i][j]+=diff[i-1][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[i][j]+=diff[i][j];
        }
    }
    return mat;
}
int main(){
    // Output: [[3,4,3],[2,2,-1],[3,-3,1]]
    vector<vector<int>>mat={{1,2,3},{1,1,0},{4,-2,2}},opr={{2,0,0,1,1},{-1,1,0,2,2}};

    vector<vector<int>>ans=applyDiff2D(mat,opr);
    for(auto &vec:ans){
        for(int &i:vec) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}