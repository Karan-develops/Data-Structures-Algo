// GFG - Fractional Knapsack
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double fractionalKnapsack(vector<int>&val,vector<int>&wt,int capacity){
    int n=val.size();
    double ans=0.0;
    
    vector<pair<int,int>>vec(n);
    
    for(int i=0;i<n;i++){
        vec[i]={val[i],wt[i]};
    }
    
    auto lambda=[](pair<int,int>&p1,pair<int,int>&p2){
        return (1.0*p1.first)/p1.second>(1.0*p2.first)/p2.second;
    };
    
    sort(begin(vec),end(vec),lambda);
    
    for(int i=0;i<n;i++){
        if(vec[i].second<=capacity){
            ans+=vec[i].first;
            capacity-=vec[i].second;
        } else {
            ans+=(1.0*vec[i].first/vec[i].second)*capacity;
            break;
        }
    }
    return ans;
}
int main(){
    // Output: 240.000000
    vector<int>val={60,100,120},wt={10,20,30};
    int capacity=50;
    // Output: 166.670000
    vector<int>val2={500},wt2={30};
    int capacity2=10;
    cout<<fractionalKnapsack(val,wt,capacity)<<endl;
    cout<<fractionalKnapsack(val2,wt2,capacity2);
    return 0;
}