// LC - 3075 - Medium - Maximize Happiness of Selected Children
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long maximumHappinessSum(vector<int>&happiness,int k){
    long long ans=0;
    int count=0;
    
    priority_queue<int>pq;
    
    for(int &i:happiness) pq.push(i);
    
    for(int i=0;i<k;i++){
        int hap=pq.top();
        pq.pop();
        
        ans+=max(hap-count,0);
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