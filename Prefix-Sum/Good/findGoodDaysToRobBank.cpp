// LC - 2100 - Medium - Find Good Days to Rob the Bank
#include<iostream>
#include<vector>
using namespace std;
vector<int> goodDaysToRobBank(vector<int>&security,int time){
    int n=security.size();

    vector<int>prefix(n,0);

    for(int i=1;i<n;i++){
        if(security[i-1]>=security[i]){
            prefix[i]=prefix[i-1]+1;
        }
    }

    vector<int>suffix(n,0);

    for(int i=n-2;i>=0;i--){
        if(security[i]<=security[i+1]){
            suffix[i]=suffix[i+1]+1;
        }
    }

    vector<int>ans;

    for(int i=time;i<n-time;i++){
        if(prefix[i]>=time && suffix[i]>=time){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    // Output: [2,3]
    vector<int>security={5,3,3,3,5,6,2};
    int time=2;
    // Output: [0,1,2,3,4]
    vector<int>security2={1,1,1,1,1};
    int time2=0;
    // Output: []
    vector<int>security3={1,2,3,4,5,6};
    int time3=2;
    return 0;
}