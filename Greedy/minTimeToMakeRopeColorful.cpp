// LC - 1578 - Medium - Minimum Time to Make Rope Colorful
#include<iostream>
#include<vector>
using namespace std;
int minCost(string colors,vector<int>&neededTime){
    int n=colors.size();
    
    int ans=0;
    int prevMax=0;
    
    for(int i=0;i<n;i++){
        if(i>0 && colors[i]!=colors[i-1]){
            prevMax=0;
        }
        
        int curr=neededTime[i];
        
        // Greedy
        ans+=min(prevMax,curr);
        
        prevMax=max(prevMax,curr);
        
    }
    return ans;
}
int main(){
    // Output: 3
    string colors="abaac";
    vector<int>neededTime={1,2,3,4,5};
    // Output: 0
    string colors2="abc";
    vector<int>neededTime2={1,2,3};
    // Output: 2
    string colors3="aabaa";
    vector<int>neededTime3={1,2,3,4,1};
    cout<<minCost(colors,neededTime)<<endl;
    cout<<minCost(colors2,neededTime2)<<endl;
    cout<<minCost(colors3,neededTime3);
    return 0;
}