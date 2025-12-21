// LC - 955 - Medium - Delete Columns to Make Sorted II
#include<iostream>
#include<vector>
using namespace std;
int minDeletionSize(vector<string>&strs){
    int m=strs.size();
    int n=strs[0].size();

    int deletion=0;

    vector<bool>alreadySorted(m,false);

    int i=0,j=0;
    
    for(j=0;j<n;j++){
        bool deleted=false;

        for(i=0;i<m-1;i++){
            if(!alreadySorted[i] && strs[i][j]>strs[i+1][j]){
                deletion++;
                deleted=true;
                break;
            }
        }

        if(deleted) continue;

        for(int i=0;i<m-1;i++){
            alreadySorted[i]=alreadySorted[i] | (strs[i][j]<strs[i+1][j]);
        }
    }

    return deletion;
}
int main(){
    // Output: 1
    vector<string>strs={"ca","bb","ac"};
    // Output: 0
    vector<string>strs2={"xc","yb","za"};
    // Output: 3
    vector<string>strs3={"zyx","wvu","tsr"};
    cout<<minDeletionSize(strs)<<endl;
    cout<<minDeletionSize(strs2)<<endl;
    cout<<minDeletionSize(strs3);
    return 0;
}