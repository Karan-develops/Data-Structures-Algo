// Count SubArrays With All Ones
// Used in -> LC - 1504 - Medium - Count Submatrices With All Ones
#include<iostream>
#include<vector>
using namespace std;
int subArray(vector<int>&nums){
    int count=0;
    int consecutiveCount=0;

    for(int &i:nums){
        if(i==1){
            count+=consecutiveCount+1;
            consecutiveCount+=1;
        } else{
            consecutiveCount=0;
        }
    }
    return count;
}
int main(){
    vector<int>nums={1,1,0,1,1,1};
    cout<<subArray(nums);
    return 0;
}