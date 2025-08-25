// LC - 498 - Medium - Diagonal Traverse
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>&mat){
    int m=mat.size();
    int n=mat[0].size();

    bool dir=false;
    int count=0;
    vector<int>ans;

    for(int col=0;col<m+n;col++){
        vector<int>temp;

        int i=min(m-1,col);
        int j=0;

        if(col>=m) j=++count;

        while(i>=0 && j<n) temp.push_back(mat[i--][j++]);

        if(dir) reverse(begin(temp),end(temp));
        dir=!dir;

        ans.insert(end(ans),begin(temp),end(temp));
    }
    return ans;
}
int main(){
    // Output: [1,2,4,7,5,3,6,8,9]
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    // Output: [1,2,3,4]
    vector<vector<int>>mat2={{1,2},{3,4}};
    return 0;
}