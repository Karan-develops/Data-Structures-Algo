// GFG - Medium - First negative in every window of size k
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> firstNegInt(vector<int>&arr,int k){
    vector<int>ans;
    int i=0,j=0,n=arr.size();
    queue<int>q;
    
    while(j<n){
        if(arr[j]<0) q.push(arr[j]);
        if(j-i+1==k){
            if(q.empty()) ans.push_back(0);
            else ans.push_back(q.front());
            
            if(arr[i]<0) q.pop();
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: [-8, 0, -6, -6]
    vector<int>arr={-8,2,3,-6,10};
    int k=2;
    // Output: [-1, -1, -7, -15, -15, 0]
    vector<int>arr2={12,-1,-7,8,-15,30,16,28};
    int k2=3;
    // Output: [0, 0]
    vector<int>arr3={12,1,3,5};
    int k3=3;
    return 0;
}