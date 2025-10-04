// LC - 1299 - Easy - Replace Elements with Greatest Element on Right Side
#include<iostream>
#include<vector>
using namespace std;
vector<int> replaceElements(vector<int>&arr){
    int n=arr.size();
    if(n==1) return {-1};

    int maxE=-1;

    for(int i=n-1;i>=0;i--){
        int val=arr[i];
        
        arr[i]=maxE;

        maxE=max(maxE,val);
    }
    return arr;
}
int main(){
    // Output: [18,6,6,6,1,-1]
    vector<int>arr={17,18,5,4,6,1};
    // Output: [-1]
    vector<int>arr2={400};
    return 0;
}