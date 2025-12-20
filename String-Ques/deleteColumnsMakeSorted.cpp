// LC - 944 - Easy - Delete Columns to Make Sorted
#include<iostream>
#include<vector>
using namespace std;
int minDeletionSize(vector<string>&strs){
    int n=strs.size();
    
    int k=strs[0].length();
    
    int ans=0;
    
    for(int i=0;i<k;i++){
        for(int j=1;j<n;j++){
            if(strs[j][i]<strs[j-1][i]){
                ans++;
                break;
            }
        }
    }
    
    return ans;
}
int main(){
    // Output: 1
    vector<string>strs={"cba","daf","ghi"};
    // Output: 0
    vector<string>strs2={"a","b"};
    // Output: 3
    vector<string>strs3={"zyx","wvu","tsr"};
    cout<<minDeletionSize(strs)<<endl;
    cout<<minDeletionSize(strs2)<<endl;
    cout<<minDeletionSize(strs3);
    return 0;
}