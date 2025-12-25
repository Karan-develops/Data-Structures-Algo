// LC - 3075 - Medium - Maximize Happiness of Selected Children
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long maximumHappinessSum(vector<int>&happiness,int k){
    sort(begin(happiness),end(happiness),greater<>());
    
    long long ans=0;
    int count=0;
    
    for(int i=0;i<k;i++){
        ans+=max(happiness[i]-count,0);
        count++;
    }
    
    return ans;
}
int main(){
    // Output: 4
    int k=2;
    vector<int>happiness={1,2,3};
    // Output: 1
    int k2=2;
    vector<int>happiness2={1,1,1,1};
    // Output: 5
    int k3=1;
    vector<int>happiness3={2,3,4,5};
    cout<<maximumHappinessSum(happiness,k)<<endl;
    cout<<maximumHappinessSum(happiness2,k2)<<endl;
    cout<<maximumHappinessSum(happiness3,k3);
    return 0;
}