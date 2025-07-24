// LC - 1503 - Medium - Last Moment Before All Ants Fall Out of a Plank
// GFG POTD
#include<iostream>
#include<vector>
using namespace std;
int getLastMoment(int n,vector<int>&left,vector<int>&right){
    int ans=0;
    
    for(int &i:left) ans=max(ans,i);
    
    for(int &i:right) ans=max(ans,n-i);
    
    return ans;
}
int main(){
    // Output: 4
    int n=4;
    vector<int>left={4,3},right={0,1};
    // Output: 7
    int n2=7;
    vector<int>left2={},right2={0,1,2,3,4,5,6,7};
    // Output: 7
    int n3=7;
    vector<int>left3={0,1,2,3,4,5,6,7},right3={};
    cout<<getLastMoment(n,left,right)<<endl;
    cout<<getLastMoment(n2,left2,right2)<<endl;
    cout<<getLastMoment(n3,left3,right3);
    return 0;
}