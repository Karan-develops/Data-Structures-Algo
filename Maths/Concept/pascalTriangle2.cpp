// LC - 119 - Easy - Pascal's Triangle II
#include<iostream>
#include<vector>
using namespace std;
vector<int> getRow(int rowIndex){
    vector<int>ans(rowIndex,1);

    for(int i=0;i<rowIndex+1;i++){
        vector<int>temp(i+1,1);
        
        for(int j=1;j<i;j++){
            temp[j]=ans[j-1]+ans[j];
        }
        ans=temp;
    }
    return ans;
}
int main(){
    // Output: [1,3,3,1]
    int rowIndex=3;
    // Output: [1]
    int rowIndex2=0;
    // Output: [1,1]
    int rowIndex3=1;
    return 0;
}